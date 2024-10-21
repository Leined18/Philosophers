/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:55:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/21 13:01:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*create_threads(t_memory *mem, void *(function)(void *))
{
	int	i;

	i = 0;
	while (i < mem->data->n_philos)
	{
		if (pthread_create(&(mem->philos)[i].thread, NULL, function,
				&(mem->philos)[i]))
			return (NULL);
		i++;
	}
	return (mem);
}

void	*join_threads(t_memory *mem)
{
	int i;

	i = 0;
	while (i < mem->data->n_philos)
	{
		if (!pthread_join((mem->philos)[i].thread, NULL))
			return (NULL);
		i++;
	}
	return (mem);
}