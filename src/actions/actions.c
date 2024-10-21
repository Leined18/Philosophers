/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:24:31 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/21 12:59:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	take_forks(t_philo *philo)
{
	if (philo->data->state)
		return ;
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken the left fork");
	pthread_mutex_lock(philo->right_fork);
	if (philo->data->state)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	print_action(philo, "has taken the right fork");
}

void	eat(t_philo *philo)
{
	if (philo->data->state)
		return ;
	print_action(philo, EATING);
	philo->last_meal = get_time();
	smart_sleep(philo->data->t_eat, philo);
	if (philo->data->state)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleep_philo(t_philo *philo)
{
	if (philo->data->state)
		return ;
	print_action(philo, SLEEPING);
	smart_sleep(philo->data->t_sleep, philo);
}

void	think(t_philo *philo)
{
	if (philo->data->state)
		return ;
	print_action(philo, THINKING);
}

void	print_action(t_philo *philo, const char *action)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id,
		action);
	pthread_mutex_unlock(&philo->data->print);
}