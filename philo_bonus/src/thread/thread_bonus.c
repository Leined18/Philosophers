/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:05:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/04 13:26:25 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_bonus.h"

void	*monitor_philos(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (is_dead(philo))
			return (NULL);
		if (!check_meals(philo->data))
		{
			philo->data->state = ALIVE;
			printf(MEALS_FINISHED);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}
