#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

static int ft_print_error(int err_code)
{
    if (err_code == E_INVALID_FORMAT)
        write(2, "Error: invalid format. Usage: ./client <PID> <message>\n", 23);
    else if (err_code == E_INVALID_PID)
        write(2, "Error: invalid PID\n", 19);
    return (err_code);
}

void send_char(int pid, unsigned char c)
{
    int bit;
    
    bit = 7;
    while (bit >= 0)
    {
        if ((c >> bit) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        bit--;
        usleep(SIGNAL_DELAY);
    }
}

int main(int argc, char **argv)
{
    char *message;
    pid_t pid;
    size_t i;

    if (argc != 3)
        return (ft_print_error(E_INVALID_FORMAT));
    pid = ft_atoi(argv[1]);
    if (pid <= 0)
        return (ft_print_error(E_INVALID_PID));

    message = argv[2];
    i = 0;
    while (message[i])
        send_char(pid, (unsigned char)message[i++]);
    send_char(pid, '\0');

    return (E_OK);
}
