/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:03:50 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/04 12:22:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_bonus.h"

static void	run_philo_cycle(t_philo *philo)
{
	while (1)
	{
		sem_wait(philo->data->dead_sem);
		if (!eat(philo))
			break ;
		if (is_dead(philo))
			break ;
		if (finished_meals(philo))
			break ;
		if (!sleep_philo(philo))
			break ;
		if (!think(philo))
			break ;
		sem_post(philo->data->dead_sem);
	}
}

static void	*routine(t_philo *philo)
{
	philo->last_meal = get_time();
	if (pthread_create(&philo->data->thread, NULL, monitor_philos,
			(void *)philo))
		return (NULL);
	if (philo->id % 2 == 0)
		smart_sleep(5);
	run_philo_cycle(philo);
	pthread_join(philo->data->thread, NULL);
	exit(1);
}

int	init_processes(t_memory *memory)
{
	int	i;

	i = 0;
	while (i < memory->data->n_philos)
	{
		memory->data->pid[i] = fork();
		if (memory->data->pid[i] == 0)
		{
			if (!routine(&memory->data->philo[i]))
				return (0);
		}
		if (memory->data->pid[i] < 0)
			return (0);
		i++;
	}
	return (1);
}
