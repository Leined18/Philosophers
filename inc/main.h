/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:23:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/21 11:59:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "actions.h"
# include "data.h"
# include "utils.h"

struct s_memory;
struct s_philo;
struct s_data;

# define ARGUMENTS_ERROR "Error: invalid arguments\n"
# define MEMORY_ERROR "Error allocating memory for data\n"
# define PHILOS_ERROR "Error allocating memory for philos\n"
# define THREAD_ERROR "Error creating threads\n"
# define THREAD_JOIN_ERROR "Error joining threads\n"
# define THREAD_CLEANUP_ERROR "Error cleaning up threads\n"
# define THREAD_SUCCESS "All threads finished\n"

#endif // PHILOSOPHERS_H