#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "minitalk_bonus.h"

static t_cli_state   g_cli;

static int ft_print_error(int err_code)
{
    if (err_code == E_INVALID_FORMAT)
        write(2, "Error: invalid format\n", 23);
    else if (err_code == E_INVALID_PID)
        write(2, "Error: invalid PID\n", 19);
    else if (err_code == E_TIMEOUT)
        write(2, "Error: timeout\n", 15);
    return (err_code);
}

static void ack_handler(int sig)
{
    if (sig == SIGUSR1)
        g_cli.acknowledged = 1;
}

static void wait_for_ack(void)
{
    int elapsed = 0;
    while (!g_cli.acknowledged)
    {
        usleep(TIMEOUT_STEP);
        if ((elapsed += TIMEOUT_STEP) >= TIMEOUT_LIMIT)
            exit(ft_print_error(E_TIMEOUT));
    }
}

void send_char(pid_t pid, unsigned char c)
{
    int bit;
    
    bit = 7;
    while (bit >= 0)
    {
        g_cli.acknowledged = 0;
        if ((c >> bit) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        bit--;
        wait_for_ack();
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

    signal(SIGUSR1, ack_handler);
    message = argv[2];
    i = 0;
    while (message[i])
        send_char(pid, (unsigned char)message[i++]);
    send_char(pid, '\0');

    return (E_OK);
}
