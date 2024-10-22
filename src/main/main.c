/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:14:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:30 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	start_simulation(t_memory *mem)
{
	mem->data->start_time = get_time();
	if (!create_threads(mem, philo_thread))
		ft_error(THREAD_ERROR, 1, mem);
	monitor_philos(mem);
	if (!join_threads(mem))
		ft_error(THREAD_JOIN_ERROR, 1, mem);
}

static void	init_memory(t_memory *mem, int ac, char **av)
{
	mem->data = NULL;
	mem->philos = NULL;
	mem->data = init_data(ac, av);
	if (!mem->data)
		ft_error(MEMORY_ERROR, 1, mem);
	mem->philos = init_philos(mem->data);
	if (!mem->philos)
		ft_error(PHILOS_ERROR, 1, mem);
}

int	main(int ac, char **av)
{
	t_memory	mem;

	if (!valid_args(ac, av))
		ft_error(ARGUMENTS_ERROR, 1, NULL);
	init_memory(&mem, ac, av);
	start_simulation(&mem);
	if (mem.data->state == 2)
		ft_success(MEALS_FINISHED, 0, NULL);
	cleanup_data(&mem.data, &mem.philos);
	ft_success(NULL, 1, NULL);
}
