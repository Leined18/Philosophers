/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:44:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/18 22:00:59 by danpalac         ###   ########.fr       */
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
	int				is_dead;
	pthread_t		thread;
}					t_philo;

long				get_current_time(void);
int					valid_args(int ac, char **av);
int					ft_atoi(const char *str);

// init

t_data				*init_data(char **av);
t_philo				*init_philos(t_data *data);

// data

void				cleanup_data(t_data *data);
void				*ft_free_error(t_philo *philo_data, char *err,
						int exit_code);
// actions

void				create_threads(t_philo *philos, void *(function)(void *));
void				destroy_mutexes(t_philo *philos);
int					is_alive(t_philo *philo);
void				*handle_thread(void *arg);
void				print_action(t_philo *philo, const char *action);
void				take_forks(t_philo *philo);
void				eat(t_philo *philo);
void				sleep_philo(t_philo *philo);
void				think(t_philo *philo);

#endif