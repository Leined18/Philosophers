/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/01 11:00:56 by danpalac         ###   ########.fr       */
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
	if (mem->philo)
	{
		free(mem->philo);
		mem->philo = NULL;
	}
	return (0);
}
