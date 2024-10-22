/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:07:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/22 09:15:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_error(char *err, int exit_code, t_memory *mem)
{
	if (err && *err)
	{
		printf("%s", RED);
		printf("%s", err);
		printf("%s", RESET);
	}
	if (mem)
		cleanup_data(&mem->data, &mem->philos);
	if (exit_code)
		exit(EXIT_FAILURE);
}

void	ft_success(char *msg, int exit_code, t_memory *mem)
{
	if (msg && *msg)
	{
		printf("%s", GREEN);
		printf("%s", msg);
		printf("%s", RESET);
	}
	if (mem)
		cleanup_data(&mem->data, &mem->philos);
	if (exit_code)
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