/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:03:50 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/06 12:51:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_bonus.h"

static void	run_philo_cycle(t_philo *philo)
{
	if (one_philo(philo))
		return ;
	while (1)
	{
		if (!eat(philo))
			return ;
		if (!sleep_philo(philo))
			return ;
		if (!think(philo))
			return ;
	}
}

static void	*routine(t_philo *philo)
{
	if (pthread_create(&philo->thread, NULL, monitor_philos, (void *)philo))
		return (NULL);
	if (!philo->start_time)
		philo->start_time = get_time();
	run_philo_cycle(philo);
	pthread_join(philo->thread, NULL);
	exit(0);
}

int	init_processes(t_memory *memory)
{
	int	i;

	i = 0;
	set_signals(sig_ph);
	while (i < memory->data->n_philos)
	{
		memory->data->pid[i] = fork();
		if (memory->data->pid[i] == 0)
		{
			routine(&memory->data->philo[i]);
		}
		else if (memory->data->pid[i] < 0)
			return (0);
		if (memory->data->state)
			return (1);
		i++;
	}
	return (1);
}
