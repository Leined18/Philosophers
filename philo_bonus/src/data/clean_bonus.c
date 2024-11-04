/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/04 12:02:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	erase(t_data *data)
{
	int	status;
	int	i;
	int	j;

	i = 0;
	j = 0;
	status = 0;
	while (i < data->n_philos)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			while (j++ < data->n_philos)
				kill(data->philo[j].pid, SIGINT);
			break ;
		}
		i++;
	}
	close_semaphores(data);
	free(data->philo);
}

int	close_semaphores(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		sem_close(&data->forks[i]);
		sem_close(&data->print_sem[i]);
		sem_close(&data->dead_sem[i]);
		i++;
	}
	sem_unlink("forks");
	sem_unlink("print_sem");
	sem_unlink("dead_sem");
	return (1);
}

int	clean_up(t_memory *mem)
{
	if (mem->data)
	{
		erase(mem->data);
		if (mem->data->pid)
		{
			free(mem->data->pid);
			mem->data->pid = NULL;
		}
		free(mem->data);
		mem->data = NULL;
	}
	return (0);
}
