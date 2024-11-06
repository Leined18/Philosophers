/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:34:40 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/06 10:42:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "config_bonus.h"

struct s_philo;

typedef struct s_data
{
	pid_t			*pid;
	long long		start_time;
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				state;
	sem_t			*forks;
	sem_t			*print_sem;
	sem_t			*dead_sem;
	sem_t			*eat_sem;
	pthread_t		thread;
	struct s_philo	*philo;
}					t_data;

typedef struct s_philo
{
	pid_t			pid;
	int				id;
	int				dead_flag;
	int				meals;
	long			last_meal;
	long long		start_time;
	t_data			*data;
	sem_t			*right_fork;
	sem_t			*left_fork;
	pthread_t		thread;
}					t_philo;

typedef struct s_memory
{
	pid_t			ppid;
	int				status;
	t_data			*data;
	t_philo			*philo;
	int				ac;
	char			**av;
}					t_memory;

#endif // STRUCTS_BONUS_H