#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig, siginfo_t *info, void *context)
{
    static unsigned char c;
    static int bit_index;

    (void)info;
    (void)context;
    c <<= 1;
    if (sig == SIGUSR2)
        c |= 1;

    if (++bit_index == 8)
    {
        write(1, &c, 1);
        if (c == '\0')
            write(1, "\n", 1);
        c = 0;
        bit_index = 0;
    }
}

int main(void)
{
    struct sigaction sa;

    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n", 1);

    sa.sa_flags     = SA_SIGINFO | SA_RESTART;
    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();

    return (0);
}
