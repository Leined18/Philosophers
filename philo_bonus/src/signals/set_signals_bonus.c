/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signals_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:57:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 09:55:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals_bonus.h"

void	setup_signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
}

void	set_signals(void (funtion)(int sig))
{
	signal(SIGUSR1, funtion);
	signal(SIGUSR2, funtion);
}
