/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:23:37 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/19 22:05:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_error(char *err, int exit_code)
{
	if (err && *err)
		printf("%s", err);
	cleanup_data(NULL, NULL);
	if (exit_code)
		exit(EXIT_FAILURE);
	return (NULL);
}

void	ft_success(char *msg)
{
	if (msg && *msg)
		printf("%s", msg);
	cleanup_data(NULL, NULL);
	exit(EXIT_SUCCESS);
}

void	cleanup_data(t_data *data, t_philo *philo)
{
	int				i;
	static t_data	*data_ptr = NULL;
	static t_philo	*philo_ptr = NULL;

	if (data || philo)
	{
		philo_ptr = philo;
		data_ptr = data;
		return ;
	}
	if (data_ptr)
	{
		i = 0;
		while (i < data_ptr->n_philos)
			pthread_mutex_destroy(&data_ptr->forks_mutexes[i++]);
		pthread_mutex_destroy(&data_ptr->print);
		free(data_ptr->forks_mutexes);
		free(data_ptr);
	}
	if (philo_ptr)
		free(philo_ptr);
}
