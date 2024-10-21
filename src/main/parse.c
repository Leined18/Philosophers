/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:07:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/21 12:09:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*ft_error(char *err, int exit_code, t_memory *mem)
{
	if (err && *err)
		printf("%s", err);
	if (mem)
		cleanup_data(&mem->data, &mem->philos);
	if (exit_code)
		exit(EXIT_FAILURE);
	return (NULL);
}

void	ft_success(char *msg, t_memory *mem)
{
	if (msg && *msg)
		printf("%s", msg);
	cleanup_data(&mem->data, &mem->philos);
	exit(EXIT_SUCCESS);
}

int	valid_args(int ac, char **av)
{
	int i;

	if (ac < 5 || ac > 6)
		return (0);
	i = 1;
	while (i < ac)
		if (ft_atoi(av[i++]) <= 0)
			return (0);
	return (1);
}