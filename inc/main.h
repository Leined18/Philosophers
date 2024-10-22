/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:23:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/22 15:10:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "actions.h"
# include "data.h"
# include "utils.h"

struct s_memory;
struct s_philo;
struct s_data;

# define SUCCESS "\033[1;32m✅ Success: Funtion finished well!\n\033[0m" // Verde
# define ERROR "\033[1;31m❌ Error: Error in function!\n\033[0m" // Rojo
# define WARNING "\033[1;33m⚠️ Warning: Warning in function!\n\033[0m" // Amarillo

# define MEALS_FINISHED "\033[1;34m🍽️ All philosophers have finished their meals!\n\033[0m"
# define ARGUMENTS_ERROR "\033[1;33m⚠️ Error: Invalid arguments provided!\n\033[0m"
# define MEMORY_ERROR "\033[1;31m🧠 Error: Memory allocation failed for data!\n\033[0m"
# define PHILOS_ERROR "\033[1;31m🧙‍♂️ Error: Memory allocation failed for philosophers!\n\033[0m"
# define THREAD_ERROR "\033[1;31m🧵 Error: Thread creation failed!\n\033[0m"
# define THREAD_JOIN_ERROR "\033[1;31m👥 Error: Joining threads failed!\n\033[0m"
# define THREAD_CLEANUP_ERROR "\033[1;31m🧹 Error: Cleanup of threads failed!\n\033[0m"
# define THREAD_SUCCESS "\033[1;32m🎉 Success: All threads finished!\n\033[0m"

void	monitor_philos(t_memory *mem);

#endif // MAIN_H