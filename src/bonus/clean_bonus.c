/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/25 12:36:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BONUS
#include "bonus.h"

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
