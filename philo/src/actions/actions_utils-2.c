/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils-2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:33:28 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/22 17:46:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

int	unlock_fork_mutex(pthread_mutex_t *fork)
{
	if (fork)
	{
		pthread_mutex_unlock(fork);
		return (0);
	}
	return (1);
}

pthread_mutex_t	*lock_fork(t_philo *philo, pthread_mutex_t *fork,
		char *fork_name)
{
	if (get_global_state(philo->data))
		return (NULL);
	if (pthread_mutex_lock(fork) == 0)
	{
		if (!print_action(philo, YELLOW, fork_name, 0))
			return (unlock_fork_mutex(fork), NULL);
		return (fork);
	}
	return (NULL);
}
int	unlock_forks(t_philo *philo)
{
	if ((philo->id % 2))
	{
		unlock_fork_mutex(philo->right_fork);
		unlock_fork_mutex(philo->left_fork);
	}
	else
	{
		unlock_fork_mutex(philo->left_fork);
		unlock_fork_mutex(philo->right_fork);
	}
	return (1);
}

int	lock_forks_mutexes(t_philo *philo, pthread_mutex_t **right_fork,
		pthread_mutex_t **left_fork)
{
	if (get_global_state(philo->data))
		return (0);
	if (philo->id % 2)
	{
		(*left_fork) = lock_fork(philo, philo->left_fork, L_FORK);
		(*right_fork) = lock_fork(philo, philo->right_fork, R_FORK);
	}
	else
	{
		(*right_fork) = lock_fork(philo, philo->right_fork, R_FORK);
		(*left_fork) = lock_fork(philo, philo->left_fork, L_FORK);
	}
	return (1);
}

int	lock_forks(t_philo *philo)
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;

	while (1)
	{
		if (!lock_forks_mutexes(philo, &right_fork, &left_fork))
			return (0);
		if (right_fork && left_fork)
			break ;
		unlock_fork_mutex(left_fork);
		unlock_fork_mutex(right_fork);
		usleep(10);
	}
	return (1);
}
