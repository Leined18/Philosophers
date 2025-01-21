#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

typedef enum e_mutex
{
	PRINT,
	READ,
	SET,
	SLEEP,
	STATE,
	TIME,
	GLOBAL,
	CHECK,
	MEAL,
	MAX_MUTEX
}					e_mutex;

typedef struct s_data
{
	long long		start_time;
	pthread_mutex_t	*forks_mutexes;
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				ntimes_eat;
	int				state;
	pthread_mutex_t	*mutexes;
	struct s_philo	*philos;
}					t_data;

typedef struct s_philo
{
	int				id;
	size_t			meals;
	long long		last_meal;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
	pthread_t		thread;
	long long		wait_time;
}					t_philo;

typedef struct s_memory
{
	t_data			*data;
	t_philo			*philos;
	pthread_mutex_t	*mutexes;
}					t_memory;

#endif // STRUCTS_H