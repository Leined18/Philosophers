/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:34:40 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 10:01:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "config_bonus.h"

struct	s_philo;
typedef struct s_state
{
	int				state;
	sem_t			*mutex;
}					t_state;

typedef struct s_data
{
	pid_t			*pid;
	int				dead_philo;
	long long		start_time;
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				state;
	sem_t			*forks;
	sem_t			*print;
	struct s_philo	*philos;
}					t_data;

typedef struct s_philo
{
	pid_t			pid;
	int				id;
	int				meals;
	long			last_meal;
	t_data			*data;
	sem_t			*right_fork;
	sem_t			*left_fork;
	pthread_t		thread;
}					t_philo;

typedef struct s_memory
{
	pid_t			pid;
	t_data			*data;
	t_philo			*philos;
	int				ac;
	char			**av;
}					t_memory;

#endif // STRUCTS_BONUS_H