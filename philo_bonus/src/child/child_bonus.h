/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:27:03 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 10:33:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHILD_BONUS_H
# define CHILD_BONUS_H

// Add any necessary includes here
# include "actions_bonus.h"
# include "colors_bonus.h"
# include "config_bonus.h"
# include "signals_bonus.h"
# include "structs_bonus.h"
# include "thread_bonus.h"

// Declare any functions or classes here
// child process
void	run_philosopher(t_philo *philo);
int		init_children(t_memory **mem);

#endif // CHILD_BONUS_H