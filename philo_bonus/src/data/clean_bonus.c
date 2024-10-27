/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/27 14:57:31 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

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
