/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:06:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/19 22:34:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// src/thread.c
#include "philosophers.h"

void	mark_simulation_end(t_data *data)
{
	pthread_mutex_lock(&data->print);
	data->stop_simulation = 1;
	pthread_mutex_unlock(&data->print);
}

int	is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	if (get_current_time() - philo->last_meal > philo->data->t_die)
	{
		printf("%d died\n", philo->id);
		pthread_mutex_unlock(&philo->data->print);
		mark_simulation_end(philo->data);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->print);
	return (1);
}

void	*handle_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->is_dead && !philo->data->stop_simulation)
	{
		take_forks(philo);
		eat(philo);
		sleep_philo(philo);
		think(philo);
		if (!is_alive(philo))
			usleep(philo->data->t_die);
	}
	return (NULL);
}
void	create_threads(t_philo *philos, void *(function)(void *), t_data *data)
{
	int	i;

	if (!philos || !function || !data)
		return ;
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, function, &philos[i]))
		{
			cleanup_data(data, philos);
			ft_error("Error creating thread\n", 1);
		}
		i++;
	}
}

void	join_threads(t_philo *philos, t_data *data)
{
	int i;

	if (!philos || !data)
		return ;

	i = 0;
	while (i < data->n_philos)
		pthread_join(philos[i++].thread, NULL);
}