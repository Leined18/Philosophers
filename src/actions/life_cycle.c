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

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	if (!philo->data->start_time)
		philo->data->start_time = get_time();
	if (one_philo(philo))
		return (NULL);
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
			return (NULL);
	}
	return (NULL);
}
