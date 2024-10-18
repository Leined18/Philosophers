#include "philo.h"

void	ft_error(char *err, int exit_code)
{
	if (err && *err)
	{
		printf(RED);
		printf("%s", err);
		printf(RESET);
	}
	if (exit_code)
		exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
int	init_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL))
	{
		ft_error("Error initializing mutex\n", 1);
		return (0);
	}
	return (1);
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
		if (!memset(&philos[i], 0, sizeof(t_philo)))
			return (NULL);
		philos[i].id = i + 1;
		if (!init_mutex(&philos[i].forks))
			return (free(philos), NULL);
		if (!init_mutex(&philos[i].print))
			return (free(philos), NULL);
		i++;
	}
	return (philos);
}

t_data	*init_data(char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	if (!memset(data, 0, sizeof(t_data)))
		return (NULL);
	data->n_philos = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5])
		data->ntimes_eat = ft_atoi(av[5]);
	return (data);
}

int	valid_args(int ac, char **av)
{
	int	i;

	if (ac < 2 || ac > 6)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= 0 || ft_atoi(av[i]) > 10000000)
			return (0);
		i++;
	}
	return (1);
}

void	create_threads(t_data *data, void *(function)(void *))
{
	int	i;

	if (!data || !function)
		return ;
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, function,
				&data->philos[i]))
		{
			free(data);
			ft_error("Error creating thread\n", 1);
		}
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_destroy(&data->philos[i].forks);
		pthread_mutex_destroy(&data->philos[i].print);
		i++;
	}
}

void	*handle_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->print);
	printf("Philo: %d\n", philo->id);
	pthread_mutex_unlock(&philo->print);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (!valid_args(ac, av))
		ft_error("Error: invalid arguments\n", 1);
	data = init_data(av);
	if (!data)
		ft_error("Error allocating memory for data\n", 1);
	data->philos = init_philos(data);
	if (!data->philos)
		ft_error("Error allocating memory for philosophers\n", 1);
	create_threads(data, handle_thread);
	destroy_mutexes(data);
	free(data->philos);
	free(data);
	return (0);
}
