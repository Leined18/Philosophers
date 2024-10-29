/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:36:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 09:54:29 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals_bonus.h"

void	handle_signal_parent(int sig)
{
	t_memory	*mem;
	t_data		*data;
	int			i;

	mem = get_mem(NULL, 1);
	data = mem->data;
	i = 0;
	if (sig == SIGUSR1)
	{
		data->state = 1;
		while (i < data->n_philos)
			kill(data->pid[i++], SIGKILL);
	}
	else if (sig == SIGUSR2)
	{
		kill(data->pid[0], SIGUSR2);
		data->state = 2;
	}
}

void	handle_signal_child(int sig)
{
	if (sig == SIGUSR1)
		exit(0);
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
	{
		printf("Signal received from %d\n", info->si_pid);
	}
}
