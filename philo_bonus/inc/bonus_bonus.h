#ifndef BONUS_H
# define BONUS_H

# include "actions_bonus.h"
# include "colors_bonus.h"
# include "structs_bonus.h"
# include "utils_bonus.h"

// check_bonus.c
int		is_alive(t_philo *philo);
int		finished_meals(t_philo *philo);
int		check_life(t_data *data, int *dead_philo);
int		check_meals(t_data *data);

// child process
void	run_philosopher(t_philo *philo);
int		init_children(t_data *data);

// Declaraciones de funciones de data
int		init_mem(t_memory *mem);
int		clean_up(t_memory *mem);

// Declaraciones de funciones de sem
int		close_semaphores(t_data *data);

// Declaraciones de funciones de thread
void	*monitor_philos(void *arg);
void	*monitor_children(void *arg);

#endif // BONUS_H