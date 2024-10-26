/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:09:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/24 14:01:01 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	if (get_time() - philo->last_meal > philo->data->t_die)
	{
		philo->data->state = 1;
		pthread_mutex_unlock(&philo->data->print);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->print);
	return (1);
}

static int	finished_meals(t_philo *philo)
{
	return (philo->meals <= 0);
}

static int	check_life(t_memory *mem, int *dead_philo)
{
	int	ph;

	ph = 0;
	while (ph < mem->data->n_philos)
	{
		if (!is_alive(&mem->philos[ph]))
		{
			*dead_philo = ph;
			pthread_mutex_unlock(mem->philos[ph].right_fork);
			pthread_mutex_unlock(mem->philos[ph].left_fork);
			return (0);
		}
		ph++;
	}
	return (1);
}

static int	check_meals(t_memory *mem)
{
	int	ph;
	int	meals_remaining;

	ph = 0;
	if (!mem->data->ntimes_eat)
		return (1);
	meals_remaining = mem->data->n_philos;
	while (ph < mem->data->n_philos)
	{
		if (finished_meals(&mem->philos[ph]))
			meals_remaining--;
		ph++;
	}
	return (meals_remaining);
}

void	monitor_philos(t_memory *mem)
{
	int	dead_philo;

	while (1)
	{
		if (!check_life(mem, &dead_philo))
		{
			printf("%s", RED);
			printf("[%lld] Philo [%d]  %s\n", get_time()
				- mem->data->start_time, dead_philo + 1, DIED);
			printf("%s", RESET);
			return ;
		}
		if (!check_meals(mem))
		{
			mem->data->state = 2;
			return ;
		}
		usleep(100);
	}
}
