/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:53:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/23 11:59:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "utils.h"

// Declaraciones de funciones de acciones
int		eat(t_philo *philo);
int		sleep_philo(t_philo *philo);
int		think(t_philo *philo);
int		print_action(t_philo *philo, const char *colour, const char *action);

// Declaraciones de funciones de ciclo de vida
int		is_alive(t_philo *philo);
void	*philo_thread(void *arg);
#endif // ACTIONS_H
