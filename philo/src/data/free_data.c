#include "utils.h"
#include <stdarg.h>

// Destruye un array de mutexes
void	destroy_mutex_array(pthread_mutex_t *mutexes, int count)
{
	int	i;

	if (!mutexes)
		return ;
	i = -1;
	while (++i < count)
		pthread_mutex_destroy(&mutexes[i]);
	free(mutexes);
}
// Limpieza de la estructura t_data
void	cleanup_data(t_data **data)
{
	if (!data || !*data)
		return ;
	// Destruir mutexes globales
	destroy_mutex_array((*data)->forks_mutexes, (*data)->n_philos);
	destroy_mutex_array((*data)->mutexes, MAX_MUTEX);
	free(*data);
	*data = NULL;
}

// Limpieza de la estructura t_philo
void	cleanup_philos(t_philo **philos)
{
	if (philos && *philos)
	{
		free(*philos);
		*philos = NULL;
	}
}

// Limpieza completa
void	cleanup(t_memory *mem)
{
	if (!mem)
		return ;
	cleanup_data(&mem->data);
	cleanup_philos(&mem->philos);
	freedom((void **)&mem);
}
