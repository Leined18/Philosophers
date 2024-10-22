/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:24:31 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/22 13:00:46 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	take_forks(t_philo *philo)
{
	if (philo->data->state)
		return (0);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		if (!print_action(philo, WHITE, L_FORK))
			return (pthread_mutex_unlock(philo->left_fork), 0);
		pthread_mutex_lock(philo->right_fork);
		if (!print_action(philo, WHITE, R_FORK))
			return (pthread_mutex_unlock(philo->right_fork),
				pthread_mutex_unlock(philo->left_fork), 0);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		if (!print_action(philo, WHITE, R_FORK))
			return (pthread_mutex_unlock(philo->right_fork), 0);
		pthread_mutex_lock(philo->left_fork);
		if (!print_action(philo, WHITE, L_FORK))
			return (pthread_mutex_unlock(philo->left_fork),
				pthread_mutex_unlock(philo->right_fork), 0);
	}
	return (1);
}

int	eat(t_philo *philo)
{
	if (!take_forks(philo))
		return (0);
	if (!print_action(philo, GREEN, EATING))
		return (0);
	smart_sleep(philo->data->t_eat, philo);
	if (philo->meals)
		philo->meals--;
	if (!is_alive(philo))
		return (pthread_mutex_unlock(philo->left_fork),
			pthread_mutex_unlock(philo->right_fork), 0);
	return (pthread_mutex_unlock(philo->left_fork),
		pthread_mutex_unlock(philo->right_fork), 1);
}

int	sleep_philo(t_philo *philo)
{
	if (!print_action(philo, BLUE, SLEEPING))
		return (0);
	smart_sleep(philo->data->t_sleep, philo);
	return (1);
}

int	think(t_philo *philo)
{
	if (!print_action(philo, YELLOW, THINKING))
		return (0);
	return (1);
}

int	print_action(t_philo *philo, const char *colour, const char *action)
{
	if (philo->data->state)
		return (0);
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->state)
		return (pthread_mutex_unlock(&philo->data->mutex), 0);
	printf("%s", colour);
	printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id,
		action);
	printf(RESET);
	if (philo->data->state)
		return (pthread_mutex_unlock(&philo->data->mutex), 0);
	return (pthread_mutex_unlock(&philo->data->mutex), 1);
}