/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:53:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/24 15:49:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "utils.h"

// Declaraciones de funciones de acciones
int		take_forks(t_philo *philo);
int		eat(t_philo *philo);
int		sleep_philo(t_philo *philo);
int		think(t_philo *philo);

// utils actions
int		forks_down(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork,
			int n);

// Declaraciones de funciones de impresión
int		print_action(t_philo *philo, const char *colour, const char *action,
			long wait_time);

// Declaraciones de funciones de ciclo de vida
int		is_alive(t_philo *philo);
void	*philo_routine(void *arg);

#endif // ACTIONS_H
