/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:23:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/20 18:37:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"

typedef struct s_data
{
	int				forks;
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				ntimes_eat;
	int				stop_simulation;
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

void				cleanup_data(t_data **data, t_philo **philos);
void				*ft_error(char *err, int exit_code, t_memory *mem);
void				ft_success(char *msg, t_memory *mem);
void				freedom(void **ptr);

// utils
void				print_action(t_philo *philo, const char *action);
long				get_current_time(void);
int					valid_args(int ac, char **av);
int					ft_atoi(const char *str);
void				smart_sleep(long time_in_ms, t_philo *philo);

// data
t_data				*allocate_and_initialize_data(char **av);
int					init_forks_mutexes(t_data *data);
t_data				*init_data(char **av);
t_philo				*init_philos(t_data *data);

// lifecycle
void				lifecycle(t_philo *philo);
int					is_alive(t_philo *philo);

// actions
void				take_forks(t_philo *philo);
void				eat(t_philo *philo);
void				sleep_philo(t_philo *philo);
void				think(t_philo *philo);
// threads
void				*handle_thread(void *arg);

void				create_threads(t_memory *mem, void *(function)(void *));
void				join_threads(t_memory *mem);

#endif
