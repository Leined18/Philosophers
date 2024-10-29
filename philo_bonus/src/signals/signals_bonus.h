/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:55:21 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 09:55:22 by danpalac         ###   ########.fr       */
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
void	handle_signal(int signal, siginfo_t *info, void *context);
void	handle_signal_parent(int sig);
void	handle_signal_child(int sig);
// set_signals_bonus.c
void	set_signals(void (funtion)(int sig));
void	setup_signal_handler(void);

#endif // SIGNALS_BONUS_H