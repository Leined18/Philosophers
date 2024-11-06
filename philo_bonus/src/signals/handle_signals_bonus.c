/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:36:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/06 10:33:06 by danpalac         ###   ########.fr       */
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
	{
		memory->data->state = DEAD;
	}
	else if (sig == SIGUSR2)
	{
		memory->data->state = ALIVE;
	}
}

void	sig_ch(int sig)
{
	if (sig == SIGUSR1)
	{
		exit(0);
	}
}
