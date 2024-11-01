/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:36:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/01 12:45:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_alive(t_philo *philo)
{
	if (get_time() - philo->last_meal > philo->data->t_die)
	{
		philo->data->state = 1;
		return (0);
	}
	return (1);
}

int	finished_meals(t_philo *philo)
{
	return (philo->meals <= 0);
}

int	check_life(t_data *data, int *dead_philo)
{
	int	ph;

	ph = 0;
	while (ph < data->n_philos)
	{
		if (!is_alive(&data->philo[ph]))
		{
			*dead_philo = ph;
			return (0);
		}
		ph++;
	}
	return (1);
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

int	check_status(t_data *data)
{
	if (data->state == 2)
		return (1);
	else if (data->state == 1)
		return (1);
	return (0);
}
