/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:06:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/18 22:04:00 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// src/thread.c
#include "philosophers.h"

int	is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	if (get_current_time() - philo->last_meal > philo->data->t_die)
	{
		printf("%d died\n", philo->id);
		pthread_mutex_unlock(&philo->data->print);
		philo->is_dead = 1;
		return (0);
	}
	pthread_mutex_unlock(&philo->data->print);
	return (1);
}

void	*handle_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->is_dead)
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		sleep_philo(philo);
		if (!is_alive(philo))
			break ;
	}
	return (NULL);
}

void	create_threads(t_philo *philos, void *(function)(void *))
{
	int		i;
	t_data	*data;

	if (!philos || !function)
		return ;
	data = philos->data;
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, function, &philos[i]))
			ft_free_error(philos, "", 1);
		pthread_join(philos[i++].thread, NULL);
		i++;
	}
}
