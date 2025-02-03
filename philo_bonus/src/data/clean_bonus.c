/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/03 17:46:31 by danpalac         ###   ########.fr       */
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
		i++;
	}
	i = 0;
	while (i < MAX_SEM)
	{
		sem_close(&data->sem[i]);
		i++;
	}
	sem_close(data->sem);
	sem_unlink("semaphores");
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
		if (mem->data->philo)
		{
			free(mem->data->philo);
			mem->data->philo = NULL;
		}
		free(mem->data);
		mem->data = NULL;
	}
	return (0);
}
