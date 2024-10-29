/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:03:50 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 10:36:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_bonus.h"

void	run_philosopher(t_philo *philo)
{
	if (!philo)
		exit(EXIT_FAILURE);
	if (!philo->data->start_time)
		philo->data->start_time = get_time();
	if (one_philo(philo))
		return ;
	while (TRUE)
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

int	init_children(t_memory **mem)
{
	int	i;

	i = 0;
	while (i < (*mem)->data->n_philos)
	{
		(*mem)->data->pid[i] = fork();
		if ((*mem)->data->pid[i] < 0)
			return (FALSE);
		if ((*mem)->data->pid[i] == 0)
		{
			signal(SIGUSR1, handle_signal_child);
			(*mem)->philos[i].pid = getpid();
			pthread_create(&(*mem)->philos[i].thread, NULL, monitor_philos,
				&(*mem)->philos[i]);
			run_philosopher(&(*mem)->philos[i]);
			pthread_detach((*mem)->philos[i].thread);
			exit(0);
		}
		i++;
	}
	return (TRUE);
}
