/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:23:37 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/18 22:05:09 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_free_error(t_philo *philo_data, char *err, int exit_code)
{
	if (err && *err)
	{
		printf("%s", err);
	}
	if (philo_data->data->forks_mutexes)
		free(philo_data->data->forks_mutexes);
	if (philo_data->data)
		cleanup_data(philo_data->data);
	if (philo_data)
		free(philo_data);
	if (exit_code)
		exit(EXIT_FAILURE);
	else
		return (NULL);
}

void	destroy_mutexes(t_philo *philos)
{
	int		i;
	t_data	*data;

	i = 0;
	data = philos->data;
	while (i < data->n_philos)
		pthread_mutex_destroy(&data->forks_mutexes[i++]);
	pthread_mutex_destroy(&data->print);
	free(data->forks_mutexes);
}

void	cleanup_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
		pthread_mutex_destroy(&data->forks_mutexes[i++]);
	pthread_mutex_destroy(&data->print);
	free(data->forks_mutexes);
}
