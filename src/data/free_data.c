/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:26:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/22 12:45:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "data.h"

void	freedom(void **ptr)
{
	if (*ptr && ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	cleanup_data(t_data **data, t_philo **philos)
{
	int i;

	if (philos)
		freedom((void **)philos);
	if (data)
	{
		if (*data)
		{
			if ((*data)->forks_mutexes)
			{
				i = 0;
				while (i < (*data)->n_philos)
				{
					pthread_mutex_destroy(&(*data)->forks_mutexes[i]);
					i++;
				}
				freedom((void **)&(*data)->forks_mutexes);
			}
			pthread_mutex_destroy(&(*data)->mutex);
			freedom((void **)&(*data)->forks);
			freedom((void **)data);
		}
	}
}