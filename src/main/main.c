/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:14:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/22 19:55:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	start_simulation(t_memory *mem)
{
	if (!create_threads(mem, philo_thread))
		return (ft_error(THREAD_ERROR, mem));
	monitor_philos(mem);
	if (!join_threads(mem))
		return (ft_error(THREAD_JOIN_ERROR, mem));
	return (ft_success(NULL, NULL));
}

static int	init_memory(t_memory *mem, int ac, char **av)
{
	mem->data = init_data(ac, av);
	if (!mem->data)
		return (ft_error(MEMORY_ERROR, mem));
	mem->philos = init_philos(mem->data);
	if (!mem->philos)
		return (ft_error(PHILOS_ERROR, mem));
	return (ft_success(NULL, NULL));
}

int	main(int ac, char **av)
{
	t_memory	mem;

	if (!valid_args(ac, av))
		ft_error(ARGUMENTS_ERROR, NULL);
	if (!init_memory(&mem, ac, av))
		return (0);
	if (!start_simulation(&mem))
		return (0);
	if (mem.data->state == 2)
		ft_success(MEALS_FINISHED, NULL);
	cleanup_data(&mem.data, &mem.philos);
	return (0);
}
