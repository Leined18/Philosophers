/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:05:57 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/03 17:48:06 by danpalac         ###   ########.fr       */
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
			sem_wait(&philo->sem[DEAD]);
			printf(RED "[%2lld] Philo [%d] %s\n" RESET, get_time()
				- philo->start_time, philo->id, DIED);
			sem_post(&philo->sem[DEAD]);
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
