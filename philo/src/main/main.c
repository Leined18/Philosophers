/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:14:19 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/20 13:43:31 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	start_simulation(t_memory *mem)
{
	pthread_t	monitor_thread;

	if (!create_threads(mem, philo_routine))
		return (ft_error(THREAD_ERROR, mem));
	if (pthread_create(&monitor_thread, NULL, monitor_philos, mem) != 0)
		return (ft_error(THREAD_ERROR, mem));
	// monitor_philos(mem);
	if (!join_threads(mem))
		return (ft_error(THREAD_JOIN_ERROR, mem));
	pthread_join(monitor_thread, NULL);
	return (ft_success(NULL, NULL));
}
int	main(int ac, char **av)
{
	t_memory	*mem;

	if (!valid_args(ac, av))
		return (ft_error(ARGUMENTS_ERROR, NULL));
	mem = init_memory(ac, av);
	if (!mem)
		return (0);
	if (!start_simulation(mem))
		return (0);
	cleanup(mem);
	return (0);
}
