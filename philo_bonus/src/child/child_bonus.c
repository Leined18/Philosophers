/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:03:50 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/04 13:34:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_bonus.h"

static void	run_philo_cycle(t_philo *philo)
{
	while (1)
	{
		if (one_philo(philo))
			return ;
		if (!eat(philo))
			return ;
		if (is_dead(philo))
			return ;
		if (finished_meals(philo))
			return ;
		if (!sleep_philo(philo))
			return ;
		if (!think(philo))
			return ;
	}
}

static void	*routine(t_philo *philo)
{
	philo->last_meal = get_time();
	if (pthread_create(&philo->thread, NULL, monitor_philos, (void *)philo))
		return (NULL);
	printf("Philosopher %d is alive\n", philo->id);
	
	if (philo->id % 2 == 0)
		smart_sleep(5);
	run_philo_cycle(philo);
	pthread_join(philo->thread, NULL);
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
			routine(&memory->data->philo[i]);
		}
		else if (memory->data->pid[i] < 0)
			return (0);
		i++;
	}
	return (1);
}
