/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:36:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/28 09:59:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_bonus.h"

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
		kill(data->pid, SIGUSR2);
		data->state = 2;
	}
}

void	handle_signal_child(int sig)
{
	if (sig == SIGUSR1)
		exit(0);
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		exit(0);
}

// signal_controller.c
void	handle_signal(int signal, siginfo_t *info, void *context)
{
	if (signal == SIGUSR1)
	{
		// Lógica para recibir notificación de muerte de un filósofo
		update_state(philo_data, TERMINATED);
	}
}

void	setup_signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
}

void	set_signals(void(funtion)(int sig))
{
	signal(SIGUSR1, funtion);
	signal(SIGUSR2, funtion);
}