#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

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
	pthread_mutex_t	print;
    pthread_mutex_t eaten;
	struct s_philo	*philos;
}					t_data;

typedef struct s_philo
{
	int				id;
	size_t			meals;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
	pthread_t		thread;
	long			wait_time;
}					t_philo;

typedef struct s_memory
{
	t_data			*data;
	t_philo			*philos;
	void			*mem;
}					t_memory;

#endif // STRUCTS_H