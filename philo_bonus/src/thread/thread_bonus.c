/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:05:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/06 10:42:49 by danpalac         ###   ########.fr       */
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
			send_signal(SIGUSR1, getppid());
			sem_wait(philo->data->dead_sem);
			printf(RED "[%2lld] Philo [%d] %s\n" RESET, get_time()
				- philo->start_time, philo->id, DIED);
			sem_post(philo->data->dead_sem);
			exit(0);
		}
		if (!check_meals(philo->data))
		{
			printf(MEALS_FINISHED);
			send_signal(SIGUSR2, getppid());
			exit(0);
		}
		usleep(100);
	}
	return (NULL);
}
