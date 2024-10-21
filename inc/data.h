#ifndef DATA_H
# define DATA_H

# include "utils.h"

struct s_memory;
struct s_philo;
struct s_data;

// Declaraciones de funciones de data
int		init_mutex(pthread_mutex_t *mutex);
t_data	*allocate_and_initialize_data(char **av);
int		init_forks_mutexes(t_data *data);
t_data	*init_data(int ac, char **av);
t_philo	*init_philos(t_data *data);

// Declaraciones de funciones de parse
void	freedom(void **ptr);
void	cleanup_data(t_data **data, t_philo **philos);
void	ft_error(char *err, int exit_code, t_memory *mem);
void	ft_success(char *msg, int exit_code, t_memory *mem);

#endif // data_H