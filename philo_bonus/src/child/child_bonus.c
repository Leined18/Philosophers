/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:03:50 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/28 09:37:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_bonus.h"

void	run_philosopher(t_philo *philo)
{
	if (!philo)
		exit(EXIT_FAILURE);
	if (!philo->data->start_time)
		philo->data->start_time = get_time();
	if (one_philo(philo))
		return ;
	while (1)
	{
		if (!philo->data->state)
		{
			if (!eat(philo))
				break ;
			if (!sleep_philo(philo))
				break ;
			if (!think(philo))
				break ;
		}
		else if (philo->data->state)
			break ;
	}
}

int	init_children(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			return (0);
		if (data->pid[i] == 0)
		{
            signal(SIGUSR1, handle_signal_child);
			(data)->philos[i].pid = getpid();
			pthread_create(&(data)->philos[i].thread, NULL, monitor_philos,
				&(data)->philos[i]);
			run_philosopher(&(data)->philos[i]);
			pthread_detach((data)->philos[i].thread);
			exit(0);
		}
	}
	return (1);
}
