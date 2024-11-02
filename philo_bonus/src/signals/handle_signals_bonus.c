/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:36:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/02 15:39:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals_bonus.h"

// SIGUSR1: signal to start the simulation
// SIGUSR2: signal to stop the simulation
// SIGKILL: signal to kill the simulation
// SIGCHLD: signal to stop the simulation
// SIGTERM: signal to stop the simulation

void	sig_ph(int sig)
{
	t_memory	*memory;

	memory = get_mem(NULL, 1);
	if (sig == SIGUSR1)
		signal_broadcast(SIGUSR1, memory);
	else if (sig == SIGUSR2)
		signal_broadcast(SIGUSR2, memory);
	else if (sig == SIGKILL || sig == SIGINT)
	{
		signal_broadcast(SIGKILL, memory);
		clean_up(memory);
		exit(0);
	}
}

void	sig_ch(int sig)
{
	if (sig == SIGUSR1)
	{
	}
	if (sig == SIGUSR2)
	{
		exit(0);
	}
}
