/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:05:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/28 09:56:12 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	*monitor_philos(void *arg)
{
	int		dead_philo;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (!check_life(philo->data, &dead_philo))
		{
			kill(getppid(), SIGUSR1);
			break ;
		}
		if (!check_meals(philo->data))
		{
			kill(getppid(), SIGUSR2);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}

void	*monitor_children(void *arg)
{
	t_data	*data;
	int		status;
	pid_t	pid;

	data = (t_data *)arg;
	(void)data;
	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid < 0)
			break ;
	}
	return (NULL);
}
