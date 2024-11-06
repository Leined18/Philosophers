/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:53:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/06 10:05:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_BONUS_H
# define ACTIONS_BONUS_H

# include "colors_bonus.h"
# include "config_bonus.h"
# include "philo_bonus.h"
# include "structs_bonus.h"
# include "utils_bonus.h"

// Declaraciones de funciones de acciones
int	take_forks(t_philo *philo);
int	eat(t_philo *philo);
int	sleep_philo(t_philo *philo);
int	think(t_philo *philo);

// utils actions
int	one_philo(t_philo *philo);
int	fork_up(t_philo *philo, sem_t **fork, const char *fork_name);
int	fork_down(sem_t **fork);

// Declaraciones de funciones de impresión
int	print_action(t_philo *philo, const char *colour, const char *action,
		long wait_time);

#endif // ACTIONS_H
