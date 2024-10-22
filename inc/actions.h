/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:53:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/22 15:20:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "main.h"
# include "utils.h"

struct s_memory;
struct s_philo;
struct s_data;

// Declaraciones de funciones de acciones
int		eat(t_philo *philo);
int		sleep_philo(t_philo *philo);
int		think(t_philo *philo);
int		print_action(t_philo *philo, const char *colour, const char *action);

// Declaraciones de funciones de ciclo de vida
int		is_alive(t_philo *philo);
void	*philo_thread(void *arg);

// actions
// Definiciones de acciones con estilo
// Definiciones de acciones
# define DIED "💀 is dead..."
# define L_FORK "🍴✨ has taken the left fork!"
# define R_FORK "🍴✨ has taken the right fork!"
# define EATING "🍽️  is eating!"
# define SLEEPING "😴 is sleeping!"
# define THINKING "🤔 is thinking!"
#endif // ACTIONS_H
