/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:14:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/20 20:31:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	t_memory	mem;

	mem.data = NULL;
	mem.philos = NULL;
	if (!valid_args(ac, av))
		ft_error("Error: invalid arguments\n", 1, &mem);
	mem.data = init_data(ac, av);
	if (!mem.data)
		ft_error("Error allocating memory for data\n", 1, &mem);
	mem.philos = init_philos(mem.data);
	if (!mem.philos)
		ft_error("Error allocating memory for philos\n", 1, &mem);
	create_threads(&mem, handle_thread);
	while (!mem.data->state)
		usleep(100);
	join_threads(&mem);
	cleanup_data(&mem.data, &mem.philos);
	ft_success("All threads finished\n", &mem);
	return (0);
}
