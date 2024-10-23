/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:53:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/23 11:59:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "colors.h"
# include "structs.h"
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// Declaraciones de funciones utilitarias
int		ft_atoi(const char *str);
int		valid_args(int ac, char **av);
void	smart_sleep(long time_in_ms, t_philo *philo);
long	get_time(void);

// Declaraciones de funciones de manejo de hilos
int		create_threads(t_memory *mem, void *(function)(void *));
int		join_threads(t_memory *mem);
int		print_action(t_philo *philo, const char *colour, const char *action);
// Declaraciones de funciones de data
int		init_mutex(pthread_mutex_t *mutex);
t_data	*allocate_and_initialize_data(char **av);
int		init_forks_mutexes(t_data *data);
t_data	*init_data(int ac, char **av);
t_philo	*init_philos(t_data *data);

// Declaraciones de funciones de parse
void	freedom(void **ptr);
void	cleanup_data(t_data **data, t_philo **philos);
int		ft_error(char *err, t_memory *mem);
int		ft_success(char *msg, t_memory *mem);

# define SUCCESS "\033[1;32m✅ Success: Funtion finished well!\n\033[0m" // Verde
# define ERROR "\033[1;31m❌ Error: Error in function!\n\033[0m" // Rojo
# define WARNING "\033[1;33m⚠️ Warning: Warning in function!\n\033[0m"
// Amarillo

# define MEALS_FINISHED "\033[1;34m🍽️ All philosophers have finished their meals!\n\033[0m"
# define ARGUMENTS_ERROR "\033[1;33m⚠️ Error: Invalid arguments provided!\n\033[0m"
# define MEMORY_ERROR "\033[1;31m🧠 Error: Memory allocation failed for data!\n\033[0m"
# define PHILOS_ERROR "\033[1;31m🧙‍♂️ Error: Memory allocation failed for philosophers!\n\033[0m"
# define THREAD_ERROR "\033[1;31m🧵 Error: Thread creation failed!\n\033[0m"
# define THREAD_JOIN_ERROR "\033[1;31m👥 Error: Joining threads failed!\n\033[0m"
# define THREAD_CLEANUP_ERROR "\033[1;31m🧹 Error: Cleanup of threads failed!\n\033[0m"
# define THREAD_SUCCESS "\033[1;32m🎉 Success: All threads finished!\n\033[0m"
// actions
// Definiciones de acciones con estilo
// Definiciones de acciones
# define DIED "💀 is dead..."
# define L_FORK "🍴✨ has taken the left fork!"
# define R_FORK "🍴✨ has taken the right fork!"
# define EATING "🍽️  is eating!"
# define SLEEPING "😴 is sleeping!"
# define THINKING "🤔 is thinking!"

#endif // UTILS_H
