/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:33:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/06 12:48:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

int	one_philo(t_philo *philo)
{
	if (philo->data->n_philos > 1)
		return (0);
	if (philo->data->n_philos == 1)
		print_action(philo, YELLOW, R_FORK, 0);
	smart_sleep(philo->data->t_die, philo);
	philo->data->state = 1;
	return (1);
}

int	unlock_fork(pthread_mutex_t *fork, int n)
{
	pthread_mutex_unlock(fork);
	return (n);
}

int	lock_fork(t_philo *philo, pthread_mutex_t *fork, char *fork_name)
{
	if (pthread_mutex_lock(fork) == 0)
	{
		if (!print_action(philo, YELLOW, fork_name, 0))
			return (unlock_fork(fork, 0));
		return (1);
	}
	return (2);
}
int	unlock_forks(t_philo *philo, int n)
{
	if (philo->id % 2)
	{
		unlock_fork(philo->right_fork, n);
		unlock_fork(philo->left_fork, n);
	}
	else
	{
		unlock_fork(philo->left_fork, n);
		unlock_fork(philo->right_fork, n);
	}
	return (n);
}

int	lock_forks(t_philo *philo)
{
	int	result;

	while (1)
	{
		result = 0;
		if (philo->id % 2 == 0)
		{
			result += lock_fork(philo, philo->right_fork, R_FORK);
			result += lock_fork(philo, philo->left_fork, L_FORK);
		}
		else
		{
			result += lock_fork(philo, philo->left_fork, L_FORK);
			result += lock_fork(philo, philo->right_fork, R_FORK);
		}
		if (result == 2)
			break ;
		if (result == 1 || result == 0)
			return (unlock_forks(philo, 0), 0);
		unlock_forks(philo, 0);
		usleep(100);
	}
	return (1);
}
