// src/main.c
#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philos;

	data = NULL;
	philos = NULL;
	if (!valid_args(ac, av))
		ft_free_error(NULL, "Error: invalid arguments\n", 1);
	data = init_data(av);
	if (!data)
		ft_free_error(NULL, "Error allocating memory for data\n", 1);
	philos = init_philos(data);
	if (!philos)
	{
		cleanup_data(data);
		ft_free_error(NULL, "Error allocating memory for philosophers\n", 1);
	}
	create_threads(philos, handle_thread);
	destroy_mutexes(philos);
	free(philos);
	free(data);
	return (0);
}
