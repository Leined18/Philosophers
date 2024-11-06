/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:28:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/06 10:47:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_bonus.h"

static int	init_semaphores(t_data **data)
{
	(*data)->forks = sem_open("forks", O_CREAT, 0644, (*data)->n_philos);
	if ((*data)->forks == SEM_FAILED)
		return (0);
	(*data)->print_sem = sem_open("print_sem", O_CREAT, 0644, 1);
	if ((*data)->print_sem == SEM_FAILED)
		return (0);
	(*data)->dead_sem = sem_open("dead_sem", O_CREAT, 0644, 1);
	if ((*data)->dead_sem == SEM_FAILED)
		return (0);
	(*data)->eat_sem = sem_open("eat_sem", O_CREAT, 0644, 1);
	if ((*data)->eat_sem == SEM_FAILED)
		return (0);
	return (1);
}

static int	init_data(t_data **data, char **av)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		return (0);
	memset(*data, 0, sizeof(t_data));
	(*data)->pid = malloc(sizeof(pid_t) * ft_atoi(av[1]));
	if (!(*data)->pid)
		return (0);
	memset((*data)->pid, 0, sizeof(pid_t) * ft_atoi(av[1]));
	(*data)->n_philos = ft_atoi(av[1]);
	(*data)->t_die = ft_atoi(av[2]);
	(*data)->t_eat = ft_atoi(av[3]);
	(*data)->t_sleep = ft_atoi(av[4]);
	if (av[5])
		(*data)->n_eat = ft_atoi(av[5]);
	return (1);
}

static int	init_philos(t_philo **philos, t_data *data)
{
	int	i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * data->n_philos);
	if (!*philos)
		return (0);
	memset(*philos, 0, sizeof(t_philo) * data->n_philos);
	i = 0;
	while (i < data->n_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].data = data;
		(*philos)[i].left_fork = &data->forks[i];
		(*philos)[i].right_fork = &data->forks[(i + 1) % data->n_philos];
		(*philos)[i].meals = data->n_eat;
        (*philos)[i].last_meal = get_time();
		i++;
	}
	return (1);
}

int	init_mem(t_memory *mem, int ac, char **av)
{
	mem->ac = ac;
	mem->av = av;
	mem->ppid = getpid();
	if (!init_data(&mem->data, mem->av))
		return (0);
	if (!init_semaphores(&mem->data))
		return (0);
	if (!init_philos(&mem->philo, mem->data))
		return (0);
	mem->data->philo = (t_philo *)mem->philo;
	get_mem(&mem, FALSE);
	return (1);
}
