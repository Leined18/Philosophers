/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:34:40 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/03 17:41:31 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "config_bonus.h"

struct s_philo;

typedef enum e_sem
{
	PRINT,
	DEAD,
	EAT,
	SLEEP,
	MAX_SEM
}					t_sem;

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
	sem_t			*sem;
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
	sem_t			*sem;
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