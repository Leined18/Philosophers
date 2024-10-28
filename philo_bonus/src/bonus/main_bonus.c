/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:39:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/28 09:43:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_bonus.h"

static int	init_simulation(t_memory *mem)
{
	pthread_t	monitor_thread;

	get_mem(mem, 0);
	set_signals(handle_signal_parent);
	if (!init_children(mem->data))
		return (0);
	pthread_create(&monitor_thread, NULL, monitor_children, mem->data);
	pthread_join(monitor_thread, NULL);
	return (1);
}
int	main(int argc, char **argv)
{
	t_memory	memory;

	memory = (t_memory){0};
	if (!valid_args(argc, argv))
		return (error(ERROR_ARGUMENTS, &memory));
	memory.ac = argc;
	memory.av = argv;
	if (!init_mem(&memory))
		return (error(ERROR_MEMORY, &memory));
	if (!init_simulation(&memory))
		return (error(ERROR_SIMULATION, &memory));
	waitpid(-1, NULL, 0);
	if (memory.data->state == 2)
		return (success(MEALS_FINISHED, &memory));
	return (success(SUCCESS, &memory));
}
