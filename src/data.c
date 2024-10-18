// src/data.c
#include "philosophers.h"

int	init_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL))
		return (0);
	return (1);
}

t_data	*init_data(char **av)
{
	t_data	*data;
	int		i;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	memset(data, 0, sizeof(t_data));
	data->n_philos = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5])
		data->ntimes_eat = ft_atoi(av[5]);
	if (!init_mutex(&data->print))
		return (cleanup_data(data), NULL);
	data->forks_mutexes = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	i = 0;
	while (i < data->n_philos)
		init_mutex(&data->forks_mutexes[i++]);
	return (data);
}

t_philo	*init_philos(t_data *data)
{
	int i;
	t_philo *philos;

	philos = (t_philo *)malloc(data->n_philos * sizeof(t_philo));
	if (!philos)
		cleanup_data(data);
	i = 0;
	while (i < data->n_philos)
	{
		memset(&philos[i], 0, sizeof(t_philo));
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].left_fork = &data->forks_mutexes[i];
		philos[i].right_fork = &data->forks_mutexes[(i + 1) % data->n_philos];
		i++;
	}
	return (philos);
}