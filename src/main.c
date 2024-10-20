/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:14:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/20 18:46:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	freedom(void **ptr)
{
	if (*ptr && ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	cleanup_data(t_data **data, t_philo **philos)
{
	int	i;

	if (philos)
		freedom((void **)philos);
	if (data)
	{
		if (*data)
		{
			if ((*data)->forks_mutexes)
			{
				i = 0;
				while (i < (*data)->n_philos)
				{
					pthread_mutex_destroy(&(*data)->forks_mutexes[i]);
					i++;
				}
				freedom((void **)&(*data)->forks_mutexes);
			}
			pthread_mutex_destroy(&(*data)->print);
			freedom((void **)data);
		}
	}
}

void	*ft_error(char *err, int exit_code, t_memory *mem)
{
	if (err && *err)
		printf("%s", err);
	cleanup_data(&mem->data, &mem->philos);
	if (exit_code)
		exit(EXIT_FAILURE);
	return (NULL);
}

void	ft_success(char *msg, t_memory *mem)
{
	if (msg && *msg)
		printf("%s", msg);
	cleanup_data(&mem->data, &mem->philos);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_memory	mem;

	mem.data = NULL;
	mem.philos = NULL;
	if (!valid_args(ac, av))
		ft_error("Error: invalid arguments\n", 1, &mem);
	mem.data = init_data(av);
	if (!mem.data)
		ft_error("Error allocating memory for data\n", 1, &mem);
	mem.philos = init_philos(mem.data);
	if (!mem.philos)
		ft_error("Error allocating memory for philos\n", 1, &mem);
	create_threads(&mem, handle_thread);
	cleanup_data(&mem.data, &mem.philos);
	ft_success("All threads finished\n", &mem);
	return (0);
}
