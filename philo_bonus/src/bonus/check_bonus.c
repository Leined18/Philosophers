/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:36:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/27 19:04:28 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_bonus.h"

static int	is_alive(t_philo *philo)
{
	if (get_time() - philo->last_meal > philo->data->t_die)
	{
		philo->data->state = 1;
		return (0);
	}
	return (1);
}

static int	finished_meals(t_philo *philo)
{
	return (philo->meals <= 0);
}

static int	check_life(t_data *data, int *dead_philo)
{
	int	ph;

	ph = 0;
	while (ph < data->n_philos)
	{
		if (!is_alive(&data->philos[ph]))
		{
			*dead_philo = ph;
			return (0);
		}
		ph++;
	}
	return (1);
}

static int	check_meals(t_data *data)
{
	int	ph;
	int	meals_remaining;

	ph = 0;
	if (!data->n_eat)
		return (1);
	meals_remaining = data->n_philos;
	while (ph < data->n_philos)
	{
		if (finished_meals(&data->philos[ph]))
			meals_remaining--;
		ph++;
	}
	return (meals_remaining);
}

void	*monitor_philos(void *arg)
{
	int		dead_philo;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		philo->data->state = 1;
		if (!check_life(philo->data, &dead_philo))
		{
			kill(getppid(), SIGUSR1);
			break;
		}
		if (!check_meals(philo->data))
		{
			kill(getppid(), SIGUSR2);
			break;
		}
		usleep(100);
	}
	return (NULL);
}
