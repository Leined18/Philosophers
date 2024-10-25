/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:27 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/25 12:49:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BONUS
#include "bonus.h"

static int	init_data(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (0);
	return (1);
}

static int	init_philos(t_philo **philos)
{
	*philos = malloc(sizeof(t_philo));
	if (!*philos)
		return (0);
	return (1);
}

int	init_mem(t_memory *mem)
{
	if (!init_data(&mem->data))
		return (0);
	if (!init_philos(&mem->philos))
		return (0);
	return (1);
}
