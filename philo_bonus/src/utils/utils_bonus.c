/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:21:44 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/02 15:30:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_memory	*get_mem(t_memory **mem, int y)
{
	static t_memory	*memory = NULL;

	if (mem)
	{
		if (!memory)
			memory = *mem;
	}
	if (y)
		return (memory);
	return (NULL);
}

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

void	smart_sleep(long time_in_ms, t_philo *philo)
{
	long long	start_time;
	long long	elapsed_time;

	start_time = get_time();
	elapsed_time = 0;
	while (1)
	{
		elapsed_time = get_time() - start_time;
		if (elapsed_time >= time_in_ms || philo->data->state)
			return ;
		usleep(100);
	}
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
