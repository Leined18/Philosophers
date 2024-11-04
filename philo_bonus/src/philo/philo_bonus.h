/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:58:07 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/04 11:51:29 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_BONUS_H
# define BONUS_BONUS_H

# include "child_bonus.h"
# include "colors_bonus.h"
# include "config_bonus.h"
# include "data_bonus.h"
# include "signals_bonus.h"
# include "structs_bonus.h"
# include "thread_bonus.h"
# include "utils_bonus.h"

// check_bonus.c
int	is_alive(t_data *data);
int	is_dead(t_philo *philo);
int	finished_meals(t_philo *philo);
int	check_meals(t_data *data);
int	check_status(t_data *data);

#endif // BONUS_H