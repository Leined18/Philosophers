/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:57:36 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 09:57:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BONUS_H
# define DATA_BONUS_H

// Add any necessary includes here
# include "colors_bonus.h"
# include "config_bonus.h"
# include "structs_bonus.h"
# include "utils_bonus.h"

// Define your data structures here

// init_bonus.c
int	init_mem(t_memory *mem, int ac, char **av);

// clean_bonus.c
int	close_semaphores(t_data *data);
int	clean_up(t_memory *mem);

#endif // DATA_BONUS_H