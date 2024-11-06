/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:36:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/06 10:35:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_dead(t_philo *philo)
{
	if (get_time() - philo->last_meal >= philo->data->t_die)
	{
		return (1);
	}
	return (0);
}

int	is_alive(t_data *data)
{
	sem_wait(data->dead_sem);
	if (data->state == DEAD)
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
	return (meals_remaining >= 0);
}
