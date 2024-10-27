/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_close_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:44:47 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/27 17:56:37 by danpalac         ###   ########.fr       */
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
