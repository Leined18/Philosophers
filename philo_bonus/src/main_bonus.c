/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:39:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/01 14:44:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	handle_child_process(void *info)
{
	t_philo	*philo;

	set_signals(sig_ch);
	pause();
	philo = (t_philo *)info;
	while (1)
	{
		printf("Philo [%d]\n", philo->id);
		sleep(3);
	}
	exit(0);
}

int	init_processes(t_memory *memory)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < memory->data->n_philos)
	{
		pid = fork_process(handle_child_process, &memory->data->philo[i]);
		if (pid == -1)
			return (0);
		memory->data->pid[i] = pid;
		i++;
	}
	return (1);
}

int	wait_processes(t_memory *memory)
{
	(void)memory;
	waitpid(-1, NULL, 0);
	return (1);
}

int	setup_signals(t_memory *memory)
{
	(void)memory;
	set_signals(sig_ph);
	signal_broadcast(SIGUSR1, memory);
	return (1);
}

int	main(int ac, char **av)
{
	t_memory	memory;

	memory = (t_memory){0};
	if (!valid_args(ac, av))
		return (error(ERROR_ARGUMENTS, &memory));
	if (!init_mem(&memory, ac, av))
		return (error(ERROR_MEMORY, &memory));
	if (!init_processes(&memory))
		return (error(ERROR_FORK, &memory));
	if (!setup_signals(&memory))
		return (error(ERROR, &memory));
	if (!wait_processes(&memory))
		return (error(ERROR, &memory));
	return (success(SUCCESS, &memory));
}
