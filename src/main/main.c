/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:14:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/21 12:43:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	start_simulation(t_memory *mem)
{
	mem->data->start_time = get_time();
	if (!create_threads(mem, philo_thread))
		ft_error(THREAD_ERROR, 1, mem);
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

void	check_philos(t_memory *mem)
{
	int	ph;

	ph = 0;
	while (1)
	{
		if (!is_alive(&mem->philos[ph]))
			print_action(mem->philos, DIED);
		ph++;
		if (ph >= mem->data->n_philos)
			ph = 0;
	}
}

int	main(int ac, char **av)
{
	t_memory	mem;

	if (!valid_args(ac, av))
		ft_error(ARGUMENTS_ERROR, 1, NULL);
	init_memory(&mem, ac, av);
	start_simulation(&mem);
	check_philos(&mem);
	cleanup_data(&mem.data, &mem.philos);
	ft_success(THREAD_SUCCESS, &mem);
	return (0);
}
