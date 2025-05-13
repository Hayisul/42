#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

/*
 * Timeout settings (microseconds)
 * — TIMEOUT_STEP: how long to sleep between ACK polls
 * — TIMEOUT_LIMIT: total time before giving up
 */
# define TIMEOUT_STEP  100000
# define TIMEOUT_LIMIT 1000000

# define E_OK             0
# define E_INVALID_FORMAT 1
# define E_INVALID_PID    2
# define E_TIMEOUT        3

/*
 * Server state: accumulates bits into a byte
 */
typedef struct s_srv_state
{
    volatile sig_atomic_t ready;
    volatile sig_atomic_t out_byte;
    int                    bit_index;
    unsigned char          current;
    pid_t                  client_pid;
}   t_srv_state;

/*
 * Client state: just counts length to justify the global
 */
typedef struct s_cli_state
{
    volatile sig_atomic_t acknowledged;
    size_t                message_len;
}   t_cli_state;

void handle_signal(int sig, siginfo_t *info, void *context);
void send_char(int pid, unsigned char c);

#endif