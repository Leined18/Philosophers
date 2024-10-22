/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:53:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/22 14:59:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "colors.h"
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// Estructuras de datos

struct s_philo;

typedef struct s_data
{
	long			start_time;
	int				*forks;
	pthread_mutex_t	*forks_mutexes;
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				ntimes_eat;
	int				state;
	pthread_mutex_t	mutex;

	struct s_philo	*philos;
}					t_data;

typedef struct s_philo
{
	int				id;
	size_t			meals;
	long			last_meal;
	int				*id_forks[2];
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
long				get_time(void);

// Declaraciones de funciones de manejo de hilos
int					create_threads(t_memory *mem, void *(function)(void *));
int					join_threads(t_memory *mem);
int					print_action(t_philo *philo, const char *colour,
						const char *action);
#endif // UTILS_H
