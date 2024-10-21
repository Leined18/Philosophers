/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:24:31 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/21 17:55:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	take_forks(t_philo *philo)
{
	if (philo->data->state)
		return (0);
	pthread_mutex_lock(philo->left_fork);
	if (!print_action(philo, BLACK, "has taken the left fork"))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	pthread_mutex_lock(philo->right_fork);
	if (!print_action(philo, BLACK, "has taken the right fork"))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	return (1);
}

int	eat(t_philo *philo)
{
	if (philo->data->state)
		return (0);
	if (!take_forks(philo))
		return (0);
	if (!print_action(philo, GREEN, EATING))
		return (0);
	philo->last_meal = get_time();
	smart_sleep(philo->data->t_eat, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

int	sleep_philo(t_philo *philo)
{
	if (philo->data->state)
		return (0);
	if (!print_action(philo, BLUE, SLEEPING))
		return (0);
	smart_sleep(philo->data->t_sleep, philo);
	return (1);
}

int	think(t_philo *philo)
{
	if (philo->data->state)
		return (0);
	if (!print_action(philo, YELLOW, THINKING))
		return (0);
	return (1);
}

int	print_action(t_philo *philo, const char *colour, const char *action)
{
	if (philo->data->state)
		return (0);
	pthread_mutex_lock(&philo->data->print);
	printf("%s", colour);
	printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id,
		action);
	printf(RESET);
	if (philo->data->state)
	{
		pthread_mutex_unlock(&philo->data->print);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->print);
	return (1);
}