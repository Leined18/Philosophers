/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:22:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 10:26:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_BONUS_H
# define CONFIG_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

// macros
# define TRUE 1
# define FALSE 0

// Definiciones de mensajes
# define SUCCESS "\033[1;32m✅ Success: Funtion finished well!\n\033[0m" // Verde
# define ERROR "\033[1;31m❌ Error: Error in function!\n\033[0m"         // Rojo
# define WARNING "\033[1;33m⚠️ Warning: Warning in function!\n\033[0m"

// Definiciones de mensajes de error

# define ERROR_ARGUMENTS "\033[1;33m⚠️ Error: Invalid arguments!\n\033[0m"
# define ERROR_MEMORY "\033[1;31m🧠 Error: allocation data!\n\033[0m"
# define ERROR_PHILOS "\033[1;31m🧙‍♂️ Error: allocation philos!\n\033[0m"
# define ERROR_THREAD "\033[1;31m🧵 Error: Thread creation failed!\n\033[0m"
# define ERROR_SEM "\033[1;31m🚦 Error: Semaphore creation failed!\n\033[0m"
# define ERROR_SEM_CLOSE "\033[1;31m🚦 Error: Semaphore close failed!\n\033[0m"
# define ERROR_SEM_UNLINK "\033[1;31m🚦 Error: Sem unlink failed!\n\033[0m"
# define ERROR_FORK "\033[1;31m🍴 Error: Fork creation failed!\n\033[0m"
# define ERROR_FORK_CLOSE "\033[1;31m🍴 Error: Fork close failed!\n\033[0m"
# define ERROR_SIMULATION "\033[1;31m🎮 Error: Simulation failed!\n\033[0m"
# define ERROR_SEND_SIGNAL "\033[1;31m📡 Error: Signal send failed!\n\033[0m"

// SUCCESSES
# define MEALS_FINISHED "\033[1;34m🍽️ all have finished their meals!\n\033[0m"

// Definiciones de mensajes de argumentos
# define DIED "💀 is dead..."
# define L_FORK "🍴✨ has taken the left fork!"
# define R_FORK "🍴✨ has taken the right fork!"
# define EATING "🍽️  is eating!"
# define SLEEPING "😴 is sleeping!"
# define THINKING "🤔 is thinking!"

#endif // CONFIG_BONUS_H