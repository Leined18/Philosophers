/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:25:36 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	init_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL))
		return (0);
	return (1);
}

int	init_forks_mutexes(t_data *data)
{
	int	i;

	data->forks_mutexes = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks_mutexes)
		return (0);
	i = 0;
	while (i < data->n_philos)
	{
		if (!init_mutex(&data->forks_mutexes[i]))
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&data->forks_mutexes[i]);
			}
			freedom((void **)&data->forks_mutexes);
			return (0);
		}
		i++;
	}
	return (1);
}

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	(void)ac;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->n_philos = ft_atoi(av[1]);
	data->forks = (int *)malloc(sizeof(int) * data->n_philos);
	if (!data->forks)
		return (freedom((void *)&data), NULL);
	memset(data, 0, sizeof(t_data));
	data->n_philos = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5])
		data->ntimes_eat = ft_atoi(av[5]);
	if (!data || !init_forks_mutexes(data))
		return (freedom((void *)&data->forks), freedom((void *)&data), NULL);
	return (data);
}

t_philo	*init_philos(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *)malloc(data->n_philos * sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < data->n_philos)
	{
		memset(&philos[i], 0, sizeof(t_philo));
		philos[i].meals = data->ntimes_eat;
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].left_fork = &data->forks_mutexes[i];
		philos[i].right_fork = &data->forks_mutexes[(i + 1) % data->n_philos];
		philos[i].last_meal = get_time();
		philos[i].id_forks[0] = &data->forks[i];
		philos[i].id_forks[1] = &data->forks[(i + 1) % data->n_philos];
		i++;
	}
	data->philos = philos;
	return (philos);
}
