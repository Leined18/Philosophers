/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/28 09:14:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	close_semaphores(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		sem_close(&data->forks[i]);
		sem_close(&data->print[i]);
		i++;
	}
	sem_unlink("forks");
	sem_unlink("print");
	return (1);
}

int	clean_up(t_memory *mem)
{
	if (mem->data)
	{
		close_semaphores(mem->data);
		if (mem->data->pid)
		{
			free(mem->data->pid);
			mem->data->pid = NULL;
		}
		free(mem->data);
		mem->data = NULL;
	}
	if (mem->philos)
	{
		free(mem->philos);
		mem->philos = NULL;
	}
	return (0);
}
