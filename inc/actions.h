#ifndef ACTIONS_H
# define ACTIONS_H

# include "main.h"
# include "utils.h"

struct s_memory;
struct s_philo;
struct s_data;

// Declaraciones de funciones de acciones
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	think(t_philo *philo);
void	print_action(t_philo *philo, const char *action);

// Declaraciones de funciones de ciclo de vida
int		is_alive(t_philo *philo);
void	*philo_thread(void *arg);

// actions
# define DIED "is dead"
# define L_FORK "has taken the left fork"
# define R_FORK "has taken the right fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"

#endif // ACTIONS_H
