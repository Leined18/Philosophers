/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:03:07 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/18 21:23:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// src/utils.c
#include "philosophers.h"

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
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

int	valid_args(int ac, char **av)
{
	int	i;

	if (ac < 2 || ac > 6)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= 0 || ft_atoi(av[i]) > 10000000)
			return (0);
		i++;
	}
	return (1);
}

long	get_current_time(void)
{
	struct timeval	tv;
	long			time_in_millis;

	gettimeofday(&tv, NULL);
	time_in_millis = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_in_millis);
}
