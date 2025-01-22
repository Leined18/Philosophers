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
	if (!philo->data->start_time)
		philo->data->start_time = get_time(NULL);
	pthread_mutex_unlock(&philo->mutexes[GLOBAL]);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	if (!(philo->id % 2))
		smart_sleep(24, philo->data);
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
		else
			return (NULL);
	}
	return (NULL);
}
