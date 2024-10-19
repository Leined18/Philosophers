// src/main.c
#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philos;

	data = NULL;
	philos = NULL;
	if (!valid_args(ac, av))
		ft_error("Error: invalid arguments\n", 1);
	data = init_data(av);
	if (!data)
		ft_error("Error allocating memory for data\n", 1);
	philos = init_philos(data);
	if (!philos)
		ft_error("Error allocating memory for philos\n", 1);
	create_threads(philos, handle_thread, data);
	cleanup_data(data, philos);
	ft_success("All threads finished\n");
	return (0);
}
