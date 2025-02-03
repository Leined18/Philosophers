/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:03:50 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/03 18:00:10 by danpalac         ###   ########.fr       */
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
	set_signals(sig_ch);
	pause();
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
			routine(&memory->data->philo[i]);
		else if (memory->data->pid[i] < 0)
			return (0);
		i++;
	}
	signal_broadcast(SIGUSR1, memory->data->pid, memory->data->n_philos);
	waitpid(-1, NULL, 0);
	return (1);
}
