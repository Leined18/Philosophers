/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:39:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/27 19:08:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_bonus.h"

static void	run_philosopher(t_philo *philo)
{
	if (!philo)
		exit(EXIT_FAILURE);
	if (!philo->data->start_time)
		philo->data->start_time = get_time();
	if (one_philo(philo))
		return ;
	while (1)
	{
		if (!philo->data->state)
		{
			if (!eat(philo))
				break ;
			if (!sleep_philo(philo))
				break ;
			if (!think(philo))
				break ;
		}
		else if (philo->data->state)
			break ;
	}
}

static void	handle_signal(int sig)
{
	t_memory	*mem;
	t_data		*data;
	int			i;

	mem = get_mem(NULL, 1);
	data = mem->data;
	i = 0;
	if (sig == SIGUSR1)
	{
		while (i < data->n_philos)
		{
			kill(data->pid[i], SIGTERM);
			i++;
		}
	}
}

static int	init_children(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			return (0);
		if (data->pid[i] == 0)
		{
			(data)->philos[i].pid = getpid();
			pthread_create(&(data)->philos[i].thread, NULL, monitor_philos,
				&(data)->philos[i]);
			run_philosopher(&(data)->philos[i]);
			pthread_detach((data)->philos[i].thread);
			exit(0);
		}
	}
	return (1);
}

void	*monitor_children(void *arg)
{
	t_data	*data;
	int		status;
	pid_t	pid;

	data = (t_data *)arg;
	(void)data;
	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid < 0)
			break ;
	}
	return (NULL);
}

static int	init_simulation(t_memory *mem)
{
	pthread_t	monitor_thread;

	get_mem(mem, 0);
	signal(SIGUSR1, handle_signal);
	if (!init_children(mem->data))
		return (0);
	pthread_create(&monitor_thread, NULL, monitor_children, &mem->data);
	pthread_join(monitor_thread, NULL);
	return (1);
}
int	main(int argc, char **argv)
{
	t_memory	memory;

	memory = (t_memory){0};
	if (!valid_args(argc, argv))
		return (error(ERROR_ARGUMENTS, &memory));
	memory.ac = argc;
	memory.av = argv;
	if (!init_mem(&memory))
		return (error(ERROR_MEMORY, &memory));
	if (!init_simulation(&memory))
		return (error(ERROR_SIMULATION, &memory));
	waitpid(-1, NULL, 0);
	if (memory.data->state == 2)
		return (success(MEALS_FINISHED, &memory));
	return (success(SUCCESS, &memory));
}
