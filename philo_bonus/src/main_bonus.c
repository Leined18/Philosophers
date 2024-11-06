/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:39:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/06 11:41:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_memory	memory;

	memset(&memory, 0, sizeof(t_memory));
	if (!valid_args(ac, av))
		return (error(ERROR_ARGUMENTS, &memory));
	if (!init_mem(&memory, ac, av))
		return (error(ERROR_MEMORY, &memory));
	if (!init_processes(&memory))
		return (error(ERROR_FORK, &memory));
	if (!wait_processes(&memory))
		return (error(ERROR, &memory));
	return (success(SUCCESS, &memory));
}
