/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:53:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/27 18:12:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "actions_bonus.h"
# include "colors_bonus.h"
# include "structs_bonus.h"
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

// Declaraciones de funciones de acciones

// Declaraciones de funciones utilitarias
int			ft_atoi(const char *str);
void		smart_sleep(long time_in_ms, t_philo *philo);
long long	get_time(void);
t_memory	*get_mem(t_memory *mem, int y);

// Declaraciones de funciones de data
int			init_mem(t_memory *mem);
int			clean_up(t_memory *mem);

// Declaraciones de funciones de sem
int			sem_unlink_error(char *name);
int			sem_close_error(sem_t *sem);
int			close_semaphores(t_data *data);

// Declaraciones de funciones de parse
int			valid_args(int ac, char **av);
int			success(char *msg, t_memory *mem);
int			error(char *msg, t_memory *mem);

// Definiciones de mensajes
# define SUCCESS "\033[1;32m✅ Success: Funtion finished well!\n\033[0m" // Verde
# define ERROR "\033[1;31m❌ Error: Error in function!\n\033[0m" // Rojo
# define WARNING "\033[1;33m⚠️ Warning: Warning in function!\n\033[0m"

// Definiciones de mensajes de error

# define ERROR_ARGUMENTS "\033[1;33m⚠️ Error: Invalid arguments provided!\n\033[0m"
# define ERROR_MEMORY "\033[1;31m🧠 Error: Memory allocation failed for data!\n\033[0m"
# define ERROR_PHILOS "\033[1;31m🧙‍♂️ Error: Memory allocation failed for philosophers!\n\033[0m"
# define ERROR_THREAD "\033[1;31m🧵 Error: Thread creation failed!\n\033[0m"
# define ERROR_SEM "\033[1;31m🚦 Error: Semaphore creation failed!\n\033[0m"
# define ERROR_SEM_CLOSE "\033[1;31m🚦 Error: Semaphore close failed!\n\033[0m"
# define ERROR_SEM_UNLINK "\033[1;31m🚦 Error: Semaphore unlink failed!\n\033[0m"
# define ERROR_FORK "\033[1;31m🍴 Error: Fork creation failed!\n\033[0m"
# define ERROR_FORK_CLOSE "\033[1;31m🍴 Error: Fork close failed!\n\033[0m"
# define ERROR_SIMULATION "\033[1;31m🎮 Error: Simulation failed!\n\033[0m"
# define ERROR_SEND_SIGNAL "\033[1;31m📡 Error: Signal send failed!\n\033[0m"

// SUCCESSES
# define MEALS_FINISHED "\033[1;34m🍽️ All philosophers have finished their meals!\n\033[0m"

// Definiciones de mensajes de argumentos
# define DIED "💀 is dead..."
# define L_FORK "🍴✨ has taken the left fork!"
# define R_FORK "🍴✨ has taken the right fork!"
# define EATING "🍽️  is eating!"
# define SLEEPING "😴 is sleeping!"
# define THINKING "🤔 is thinking!"

#endif // UTILS_H
