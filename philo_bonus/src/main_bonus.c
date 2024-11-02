/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:39:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/02 15:40:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	setup_signals(t_memory *memory)
{
	(void)memory;
	set_signals(sig_ph);
	pause();
	return (1);
}

int	main(int ac, char **av)
{
	t_memory	memory;

	memory = (t_memory){0};
	if (!valid_args(ac, av))
		return (error(ERROR_ARGUMENTS, &memory));
	if (!init_mem(&memory, ac, av))
		return (error(ERROR_MEMORY, &memory));
	if (!init_processes(&memory))
		return (error(ERROR_FORK, &memory));
	if (!setup_signals(&memory))
		return (error(ERROR, &memory));
	if (!wait_processes(&memory))
		return (error(ERROR, &memory));
	return (success(SUCCESS, &memory));
}
