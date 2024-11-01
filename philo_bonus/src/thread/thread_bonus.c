/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:05:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/01 12:49:31 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_bonus.h"

int	init_threads(void *(monitor)(void *), t_memory *mem, int n)
{
	int	i;
	int	ret;

	i = 0;
	while (i < n)
	{
		ret = pthread_create(&mem->data->philo[i].thread, NULL, monitor,
				&mem->data->philo[i]);
		if (ret)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
