/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils-1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:22:43 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/21 10:24:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	take_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutexes[MEAL]);
	philo->meals -= 1;
	pthread_mutex_unlock(&philo->mutexes[MEAL]);
}

int	get_meals(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(&philo->mutexes[MEAL]);
	meals = philo->meals;
	pthread_mutex_unlock(&philo->mutexes[MEAL]);
	return (meals);
}
