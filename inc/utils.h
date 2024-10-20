#ifndef UTILS_H
# define UTILS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// Definiciones de colores para imprimir en la terminal
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"

// Estructuras de datos
typedef struct s_data
{
	int				forks;
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				ntimes_eat;
	int				state;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks_mutexes;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				time_stamp;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
	pthread_t		thread;
}					t_philo;

typedef struct s_memory
{
	t_data			*data;
	t_philo			*philos;
}					t_memory;

// Declaraciones de funciones utilitarias
int					ft_atoi(const char *str);
int					valid_args(int ac, char **av);
void				smart_sleep(long time_in_ms, t_philo *philo);
long				get_current_time(void);

// Declaraciones de funciones de manejo de hilos
void				*handle_thread(void *arg);
void				*create_threads(t_memory *mem, void *(function)(void *));
void				*join_threads(t_memory *mem);

#endif // UTILS_H
