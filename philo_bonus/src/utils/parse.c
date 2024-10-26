/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:07:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/26 08:39:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

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
