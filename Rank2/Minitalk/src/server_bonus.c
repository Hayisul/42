#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minitalk_bonus.h"

static t_srv_state   g_state;

void handle_signal(int sig, siginfo_t *info, void *context)
{
    (void)context;

    if (info && info->si_pid > 0)
        g_state.client_pid = info->si_pid;
    g_state.current <<= 1;
    if (sig == SIGUSR2)
        g_state.current |= 1;

    if (++g_state.bit_index == 8)
    {
        g_state.out_byte = g_state.current;
        g_state.ready    = 1;
        g_state.current     = 0;
        g_state.bit_index = 0;
    }
    kill(g_state.client_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;

    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n", 1);

    sa.sa_sigaction = handle_signal;
    sa.sa_flags     = SA_SIGINFO | SA_RESTART;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
    {
        pause();
        if (g_state.ready)
        {
            char  c = (char)g_state.out_byte;
            write(1, &c, 1);
            if (c == '\0')
                write(1, "\n", 1);
            g_state.ready = 0;
        }
    }
    return (0);
}
