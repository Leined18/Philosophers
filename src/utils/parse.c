/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:07:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/23 16:25:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_error(char *err, t_memory *mem)
{
	if (err && *err)
	{
		printf("%s", RED);
		printf("%s", err);
		printf("%s", RESET);
	}
	if (mem)
		cleanup_data(&mem->data, &mem->philos);
	return (0);
}

int	ft_success(char *msg, t_memory *mem)
{
	if (msg && *msg)
	{
		printf("%s", GREEN);
		printf("%s", msg);
		printf("%s", RESET);
	}
	if (mem)
		cleanup_data(&mem->data, &mem->philos);
	return (1);
}

int	valid_args(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (0);
	if (ft_atoi(av[2]) + ft_atoi(av[3]) + ft_atoi(av[4]) > 60000)
		return (0);
	i = 1;
	if (ft_atoi(av[i]) > 200)
		return (0);
	while (i < ac)
		if (ft_atoi(av[i++]) <= 0)
			return (0);
	return (1);
}
