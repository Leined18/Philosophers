/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:40:03 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/15 14:43:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	update_last_meal(t_philo *philo, long time)
{
	if (get_global_state(philo->data))
		return (0);
	pthread_mutex_lock(&philo->mutexes[MEAL]);
	philo->last_meal = time;
	if (get_global_state(philo->data))
		return (pthread_mutex_unlock(&philo->mutexes[MEAL]), 0);
	pthread_mutex_unlock(&philo->mutexes[MEAL]);
	return (1);
}

long	get_last_meal(t_philo *philo)
{
	long	time;

	if (get_global_state(philo->data))
		return (0);
	pthread_mutex_lock(&philo->mutexes[MEAL]);
	time = get_time(&philo->mutexes[TIME]) - philo->last_meal;
	if (get_global_state(philo->data))
		return (pthread_mutex_unlock(&philo->mutexes[MEAL]), 0);
	pthread_mutex_unlock(&philo->mutexes[MEAL]);
	return (time);
}

int	set_global_state(t_data *data, int state)
{
	if (get_global_state(data))
		return (0);
	pthread_mutex_lock(&data->mutexes[STATE]);
	data->state = state;
	pthread_mutex_unlock(&data->mutexes[STATE]);
	return (1);
}

int	get_global_state(t_data *data)
{
	int	state;

	pthread_mutex_lock(&data->mutexes[STATE]);
	state = data->state;
	pthread_mutex_unlock(&data->mutexes[STATE]);
	return (state);
}

