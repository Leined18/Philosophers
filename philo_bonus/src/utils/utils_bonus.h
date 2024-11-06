/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:53:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/06 10:12:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "colors_bonus.h"
# include "config_bonus.h"
# include "data_bonus.h"
# include "structs_bonus.h"

// Declaraciones de funciones utilitarias
int			ft_atoi(const char *str);
int			smart_sleep(size_t ms, t_philo *philo);
long long	get_time(void);
t_memory	*get_mem(t_memory **mem, int y);
// Declaraciones de funciones de parse

int			valid_args(int ac, char **av);
int			success(char *msg, t_memory *mem);
int			error(char *msg, t_memory *mem);

#endif // UTILS_BONUS_H
