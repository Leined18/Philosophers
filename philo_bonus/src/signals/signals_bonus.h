/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:55:21 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/04 12:10:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_BONUS_H
# define SIGNALS_BONUS_H

# include "colors_bonus.h"
# include "config_bonus.h"
# include "structs_bonus.h"
# include "utils_bonus.h"
/* # include <asm-generic/siginfo.h>
# include <asm-generic/signal-defs.h>
# include <bits/sigaction.h> */
// Declaraciones de funciones de signals

// handle_signals_bonus.c
void	sig_ch(int sig);
void	sig_ph(int sig);
// signals_utils_bonus.c
void	set_signals(void(funtion)(int sig));
void	setup_signal_handler(void (*signal_handler)(int signal, siginfo_t *info,
				void *context));
int		send_signal(int signal, int pid);
int		signal_broadcast(int signal, t_data *data);

#endif // SIGNALS_BONUS_H