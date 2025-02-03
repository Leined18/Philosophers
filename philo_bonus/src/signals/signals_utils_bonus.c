/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:57:58 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/03 17:53:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals_bonus.h"

void	setup_signal_handler(void (*signal_handler)(int signal, siginfo_t *info,
			void *context))
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
}

void	set_signals(void(funtion)(int sig))
{
	signal(SIGUSR1, funtion);
	signal(SIGUSR2, funtion);
	signal(SIGINT, funtion);
	signal(SIGTERM, funtion);
	signal(SIGCHLD, funtion);
	signal(SIGKILL, funtion);
}

int	send_signal(int signal, int pid)
{
	if (kill(pid, signal) == -1)
		return (FALSE);
	return (TRUE);
}

int	signal_broadcast(int signal, int *pid, int n_pid)
{
	int	i;

	i = 0;
	while (i < n_pid)
	{
		kill(pid[i], signal);
		usleep(100);
		i++;
	}
	return (1);
}