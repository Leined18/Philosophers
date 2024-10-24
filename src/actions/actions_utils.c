/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:33:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/24 16:12:07 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

int	lock_forks(t_philo *philo, int n)
{
	if ((philo->id % 2))
	{
		pthread_mutex_lock(philo->left_fork);
		if (!print_action(philo, YELLOW, L_FORK, 0))
			return (unlock_forks(philo, 0));
		if (!print_action(philo, YELLOW, R_FORK, 0))
			return (unlock_forks(philo, 0));
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		if (!print_action(philo, YELLOW, R_FORK, 0))
			return (unlock_forks(philo, 0));
		pthread_mutex_lock(philo->left_fork);
		if (!print_action(philo, YELLOW, L_FORK, 0))
			return (unlock_forks(philo, 0));
	}
	return (n);
}

int	unlock_forks(t_philo *philo, int n)
{
	if (philo->id % 2)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	return (n);
}

int	check_priority(t_philo *philos, int n_philos)
{
	int			i;
	long long	highest_wait_time;
	int			priority_philo;
	long long	wait_time;

	highest_wait_time = 0;
	priority_philo = -1;
	wait_time = 0;
	i = 0;
	while (i < n_philos)
	{
		wait_time = get_time() - philos[i].last_meal;
		if (wait_time > highest_wait_time)
		{
			highest_wait_time = wait_time;
			priority_philo = i;
		}
		i++;
	}
	return (priority_philo);
}
