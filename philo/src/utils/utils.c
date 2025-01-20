/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:21:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/20 13:03:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

void	smart_sleep(long time_in_ms, t_data *data)
{
	long long	start_time;
	long long	elapsed_time;

	start_time = get_time(NULL);
	elapsed_time = 0;
	while (1)
	{
		elapsed_time = get_time(NULL) - start_time;
		if (elapsed_time >= time_in_ms || get_global_state(data))
			return ;
		usleep(100);
	}
}

long long	get_time(pthread_mutex_t *time_mutex)
{
	struct timeval	tv;
	long long		time_in_ms;

	if (time_mutex)
		pthread_mutex_lock(time_mutex);
	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	if (time_mutex)
		pthread_mutex_unlock(time_mutex);
	return (time_in_ms);
}

long	get_time_elapsed(t_philo *philo, int start_time)
{
	return (get_time(&philo->mutexes[TIME]) - start_time);
}
