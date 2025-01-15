/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:16:21 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/15 15:02:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "utils.h"

void	freedom(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	print_dead(t_data *data, int dead_philo)
{
	printf("%s", RED);
	printf("[%lld] Philo [%d]  %s\n", get_time(&data->mutexes[PRINT])
		- data->start_time, dead_philo + 1, DIED);
	printf("%s", RESET);
}

int	one_philo(t_data **data)
{
	t_philo	*philo;

	if ((*data)->n_philos > 1)
		return (0);
	if ((*data)->n_philos == 1)
	{
		(*data)->start_time = get_time(&(*data)->mutexes[TIME]);
		philo = malloc(sizeof(t_philo));
		memset(philo, 0, sizeof(t_philo));
		philo->mutexes = (*data)->mutexes;
		philo->data = (*data);
		philo->id = 1;
		print_action(philo, YELLOW, R_FORK, 0);
		freedom((void **)&philo);
		smart_sleep((*data)->t_die, (*data));
		print_dead((*data), 0);
		cleanup_data(data);
		return (1);
	}
	return (0);
}
