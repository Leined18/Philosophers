#ifndef ACTIONS_H
# define ACTIONS_H

# include "utils.h"

// Declaraciones de funciones de acciones
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	think(t_philo *philo);
void	print_action(t_philo *philo, const char *action);

// Declaraciones de funciones de ciclo de vida
void	lifecycle(t_philo *philo);
int		is_alive(t_philo *philo);

#endif // ACTIONS_H
