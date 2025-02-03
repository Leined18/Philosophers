/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:36:35 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/03 18:00:49 by danpalac         ###   ########.fr       */
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
	if (sig == SIGUSR1)
	{
	}
	else if (sig == SIGUSR2)
	{
	}
}

void	sig_ch(int sig)
{
	if (sig == SIGUSR1)
	{
		printf(SUCCESS);
	}
	if (sig == SIGUSR2)
	{
		exit(0);
	}
}
