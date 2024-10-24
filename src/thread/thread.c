/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:55:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/24 12:29:31 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	create_threads(t_memory *mem, void *(function)(void *))
{
	int	i;

	i = 0;
	if (!mem->data)
		return (ft_error(ERROR, mem));
	while (i < mem->data->n_philos)
	{
		if (pthread_create(&(mem->philos)[i].thread, NULL, function,
				&(mem->philos)[i]))
			return (0);
		i++;
	}
	return (1);
}

int	join_threads(t_memory *mem)
{
	int	i;

	i = 0;
	if (!mem->data)
		return (ft_error(ERROR, mem));
	while (i < mem->data->n_philos)
	{
		if (pthread_join((mem->philos)[i].thread, NULL))
			return (0);
		i++;
	}
	return (1);
}
