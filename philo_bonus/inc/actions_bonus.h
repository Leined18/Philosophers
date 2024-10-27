/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:53:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/27 18:17:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "utils_bonus.h"
# include "structs_bonus.h"

// Declaraciones de funciones de acciones
int	take_forks(t_philo *philo);
int	eat(t_philo *philo);
int	sleep_philo(t_philo *philo);
int	think(t_philo *philo);

// utils actions
int	one_philo(t_philo *philo);
int	fork_up(t_philo *philo, sem_t *fork, const char *fork_name);
int	fork_down(sem_t *fork, sem_t *sem);

// Declaraciones de funciones de impresión
int	print_action(t_philo *philo, const char *colour, const char *action,
		long wait_time);

#endif // ACTIONS_H
