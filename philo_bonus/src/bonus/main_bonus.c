/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:39:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 10:30:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_bonus.h"

static int	init_simulation(t_memory *mem)
{
	pthread_t	monitor_thread;

	set_signals(handle_signal_parent);
	if (!init_children(&mem))
		return (FALSE);
	if (pthread_create(&monitor_thread, NULL, monitor_children, mem->data))
		return (FALSE);
	if (pthread_join(monitor_thread, NULL), FALSE)
		return (FALSE);
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_memory	memory;

	memory = (t_memory){0};
	if (!valid_args(ac, av))
		return (error(ERROR_ARGUMENTS, &memory));
	if (!init_mem(&memory, ac, av))
		return (error(ERROR_MEMORY, &memory));
	if (!init_simulation(&memory))
		return (error(ERROR_SIMULATION, &memory));
	waitpid(-1, NULL, 0);
	if ((memory.data->state == 2))
		return (success(MEALS_FINISHED, &memory));
	return (success(SUCCESS, &memory));
}
