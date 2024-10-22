/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:30:00 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/20 20:30:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo->data->start_time)
		philo->data->start_time = get_time();
	while (1)
	{
		if (!philo->data->state)
		{
			if (!eat(philo))
				return (NULL);
			if (!sleep_philo(philo))
				return (NULL);
			if (!think(philo))
				return (NULL);
		}
		else if (philo->data->state)
			break ;
	}
	return (NULL);
}

int	is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (get_time() - philo->last_meal > philo->data->t_die)
	{
		philo->data->state = 1;
		pthread_mutex_unlock(&philo->data->mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->mutex);
	return (1);
}
