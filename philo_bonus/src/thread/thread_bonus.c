/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:05:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/04 12:13:51 by danpalac         ###   ########.fr       */
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
			/* signal_broadcast(SIGKILL, philo->data); */
			exit(0);
		}
		if (!check_meals(philo->data))
		{
			philo->data->eat_flag = 1;
			sem_wait(philo->data->print_sem);
			printf(MEALS_FINISHED);
			sem_post(philo->data->print_sem);
			/* signal_broadcast(SIGKILL, philo->data); */
			exit(0);
		}
		usleep(100);
	}
	return (NULL);
}
