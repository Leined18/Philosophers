/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/26 08:36:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_bonus.h"

int	clean_up(t_memory *mem)
{
	if (mem->data)
	{
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
