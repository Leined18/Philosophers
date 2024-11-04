/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:36:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/04 12:00:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_dead(t_philo *philo)
{
	sem_wait(philo->data->eat_sem);
	if (get_time() - philo->last_meal >= philo->data->t_die)
	{
		printf(RED "%lld %d %s\n" RESET, get_time() - philo->data->start_time,
			philo->id, DIED);
		sem_wait(philo->data->print_sem);
		philo->data->dead_flag = 1;
		return (1);
	}
	sem_post(philo->data->eat_sem);
	return (0);
}

int	is_alive(t_data *data)
{
	sem_wait(data->dead_sem);
	if (data->dead_flag == 1)
	{
		sem_post(data->dead_sem);
		return (0);
	}
	sem_post(data->dead_sem);
	return (1);
}

int	finished_meals(t_philo *philo)
{
	return (philo->meals <= 0);
}

int	check_meals(t_data *data)
{
	int	ph;
	int	meals_remaining;

	ph = 0;
	if (!data->n_eat)
		return (1);
	meals_remaining = data->n_philos;
	while (ph < data->n_philos)
	{
		if (finished_meals(&data->philo[ph]))
			meals_remaining--;
		ph++;
	}
	return (meals_remaining);
}
