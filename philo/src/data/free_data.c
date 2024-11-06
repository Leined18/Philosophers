#include "utils.h"
#include <stdarg.h>

void	freedom(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	destroy_mutexes(pthread_mutex_t *forks, int n, ...)
{
	int				i;
	va_list			args;
	pthread_mutex_t	**mutex;

	i = 0;
	if (forks)
	{
		while (i < n)
		{
			pthread_mutex_destroy(&forks[i]);
			i++;
		}
		freedom((void **)&forks);
	}
	va_start(args, n);
	while (1)
	{
		mutex = va_arg(args, pthread_mutex_t **);
		if (!mutex || !*mutex)
			break ;
		pthread_mutex_destroy(*mutex);
	}
	va_end(args);
}

void	cleanup_data(t_data **data, t_philo **philos)
{
	if (philos && *philos)
		freedom((void **)philos);
	if (data && *data)
	{
		destroy_mutexes((*data)->forks_mutexes, (*data)->n_philos,
			&(*data)->print, &(*data)->eaten, NULL);
		freedom((void **)data);
	}
}

void	cleanup(t_memory *mem)
{
	cleanup_data(&(mem->data), &(mem->philos));
}
