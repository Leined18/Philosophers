/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:21:44 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/22 12:11:12 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0, sign = 1, i = 0;
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

void	smart_sleep(long time_in_ms, t_philo *philo)
{
	long	start_time;
	long	elapsed_time;

	start_time = get_time();
	while (1)
	{
		elapsed_time = get_time() - start_time;
		if (elapsed_time >= time_in_ms || philo->data->state)
			break ;
		usleep(100);
	}
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	try_lock_and_print(pthread_mutex_t *fork, t_philo *philo,
		const char *fork_name)
{
	if (philo->data->state)
		return (0);

	pthread_mutex_lock(fork);
	if (!print_action(philo, WHITE, fork_name))
	{
		pthread_mutex_unlock(fork);
		return (0);
	}
	return (1);
}