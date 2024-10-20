/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:55:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/20 18:44:27 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*handle_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->stop_simulation)
	{
		lifecycle(philo);
		if (!is_alive(philo))
			break ;
	}
	return (NULL);
}

void	create_threads(t_memory *mem, void *(function)(void *))
{
	int	i;

	i = 0;
	while (i < mem->data->n_philos)
	{
		if (pthread_create(&(mem->philos)[i].thread, NULL, function,
				&(mem->philos)[i]))
			ft_error("Error creating thread\n", 1, mem);
		pthread_join((mem->philos)[i].thread, NULL);
		i++;
	}
}

void	join_threads(t_memory *mem)
{
	int i;

	i = 0;
	while (i < mem->data->n_philos)
	{
		pthread_join((mem->philos)[i].thread, NULL);
		i++;
	}
}