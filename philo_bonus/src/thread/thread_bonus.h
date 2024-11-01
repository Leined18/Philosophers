/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:56:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/01 12:47:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_BONUS_H
# define THREAD_BONUS_H

// Add any necessary includes here
# include "colors_bonus.h"
# include "config_bonus.h"
# include "structs_bonus.h"
# include "philo_bonus.h"
// Define any necessary constants or macros here

// Declare any necessary structs or types here

// Declare any necessary function prototypes here
void	*monitor_philos(void *arg);
void	*monitor_children(void *arg);
int		init_threads(void *(monitor)(void *), t_memory *mem, int n);

#endif /* THREAD_BONUS_H */