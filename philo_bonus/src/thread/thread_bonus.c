/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:05:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/05 11:47:40 by danpalac         ###   ########.fr       */
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
		{
            sem_wait(philo->data->dead_sem);
			printf(RED "[%2lld] Philo [%d] %s\n" RESET, get_time()
				- philo->data->start_time, philo->id, DIED);
            sem_post(philo->data->dead_sem);
            return (NULL);
		}
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
