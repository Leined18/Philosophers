/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:25:36 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/20 13:52:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	init_forks_mutexes(t_data *data)
{
	int	i;

	data->forks_mutexes = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks_mutexes)
		return (0);
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&data->forks_mutexes[i], NULL))
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&data->forks_mutexes[i]);
			}
			free(data->forks_mutexes);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	init_data_mutexes(t_data *data)
{
	int	i;

	data->mutexes = malloc(sizeof(pthread_mutex_t) * MAX_MUTEX);
	if (!data->mutexes)
		return (0);
	i = 0;
	while (i < MAX_MUTEX)
	{
		if (pthread_mutex_init(&data->mutexes[i], NULL))
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&data->mutexes[i]);
			}
			free(data->mutexes);
			return (0);
		}
		i++;
	}
	return (1);
}

static void	*init_data(int ac, char **av)
{
	t_data	*data;

	(void)ac;
	(data) = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	memset(data, 0, sizeof(t_data));
	if (!data)
		return (NULL);
	(data)->n_philos = ft_atoi(av[1]);
	(data)->t_die = ft_atoi(av[2]);
	(data)->t_eat = ft_atoi(av[3]);
	(data)->t_sleep = ft_atoi(av[4]);
	(data)->start_time = 0;
	if (av[5])
		(data)->ntimes_eat = ft_atoi(av[5]);
	if (one_philo((data)->t_die, (data)->n_philos))
		return (freedom((void **)&data), NULL);
	if (!init_forks_mutexes((data)))
		return (freedom((void **)&data), NULL);
	if (!init_data_mutexes((data)))
		return (freedom((void **)&data),
			destroy_mutex_array((data)->forks_mutexes, (data)->n_philos), NULL);
	return (data);
}

static t_philo	*init_philos(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *)malloc(data->n_philos * sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < data->n_philos)
	{
		philos[i].meals = data->ntimes_eat;
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].mutexes = data->mutexes;
		philos[i].left_fork = &data->forks_mutexes[i];
		philos[i].right_fork = &data->forks_mutexes[(i + 1) % data->n_philos];
		philos[i].last_meal = get_time(NULL);
		i++;
	}
	data->philos = philos;
	return (philos);
}

t_memory	*init_memory(int ac, char **av)
{
	t_memory	*mem;

	mem = (t_memory *)malloc(sizeof(t_memory));
	if (!mem)
		return (NULL);
	memset(mem, 0, sizeof(t_memory));
	mem->data = init_data(ac, av);
	if (!mem->data)
		return (free(mem), NULL);
	mem->philos = init_philos(mem->data);
	if (!mem->philos)
		return (free(mem->data), free(mem), NULL);
	mem->mutexes = mem->data->mutexes;
	return (ft_success(NULL, NULL), mem);
}
