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

static void	set_start_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutexes[GLOBAL]);
	pthread_mutex_lock(&philo->mutexes[READ]);
	if (!philo->data->start_time)
		philo->data->start_time = get_time(&philo->mutexes[TIME]);
	pthread_mutex_unlock(&philo->mutexes[READ]);
	pthread_mutex_unlock(&philo->mutexes[GLOBAL]);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	set_start_time(philo);
	while (1)
	{
		if (!get_global_state(philo->data))
		{
			if (!eat(philo))
				return (NULL);
			if (!sleep_philo(philo))
				return (NULL);
			if (!think(philo))
				return (NULL);
		}
		else if (get_global_state(philo->data))
			return (NULL);
	}
	return (NULL);
}
