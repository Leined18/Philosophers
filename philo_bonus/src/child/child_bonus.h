/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:27:03 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/02 15:31:05 by danpalac         ###   ########.fr       */
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
int		init_processes(t_memory *memory);
pid_t	fork_process(void child_func(void *), void *info);
int		wait_processes(t_memory *memory);

#endif // CHILD_BONUS_H