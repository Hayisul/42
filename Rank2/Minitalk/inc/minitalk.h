#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

/* Delay between bit‐signals in µs */
# define SIGNAL_DELAY 5000

/*
 * Return / error codes
 */
# define E_OK             0
# define E_INVALID_FORMAT 1
# define E_INVALID_PID    2

void handle_signal(int sig, siginfo_t *info, void *context);
void send_char(int pid, unsigned char c);

#endif