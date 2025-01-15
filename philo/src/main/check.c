/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:09:51 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/15 15:35:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_alive(t_philo *philo)
{
	long long	time_last_meal;
	int			t_to_die;

	pthread_mutex_lock(&philo->mutexes[CHECK]); // Protege acceso a last_meal
	time_last_meal = get_last_meal(philo);
	t_to_die = philo->data->t_die;
	pthread_mutex_lock(&philo->mutexes[CHECK]);
	if (time_last_meal > t_to_die)
	{
		set_global_state(philo->data, 1);
		// Asegúrate de bloquear el mutex para mutexes[CHECK]
		pthread_mutex_unlock(&philo->mutexes[CHECK]);
		return (0);
	}
	pthread_mutex_unlock(&philo->mutexes[CHECK]);
	// Desbloqueo de mutexes[CHECK]
	return (1);
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
			return (0);
		}
		ph++;
	}
	return (1);
}
static int	finished_meals(t_philo *philo)
{
	return (philo->meals <= 0);
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
			print_dead(mem->data, dead_philo);
			return ;
		}
		if (!check_meals(mem))
		{
			set_global_state(mem->data, 2);
			return ;
		}
		usleep(100);
	}
}
