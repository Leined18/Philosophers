/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:03:50 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/02 15:38:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_bonus.h"

static void	handle_child_process(void *info)
{
	t_philo	*philo;

	set_signals(sig_ch);
	pause();
	philo = (t_philo *)info;
	printf("Philo [%d]\n", philo->id);
	exit(0);
}

int	init_processes(t_memory *memory)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < memory->data->n_philos)
	{
		pid = fork_process(handle_child_process, &memory->data->philo[i]);
		if (pid == -1)
			return (0);
		memory->data->pid[i] = pid;
		i++;
	}
	return (1);
}
