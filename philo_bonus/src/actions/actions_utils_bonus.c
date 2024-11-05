/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:33:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/05 11:34:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions_bonus.h"

int	fork_up(t_philo *philo, sem_t **fork, const char *fork_name)
{
	if (philo->data->state == DEAD)
		return (0);
	sem_wait(*fork);
	return (print_action(philo, YELLOW, fork_name, 0));
}

int	fork_down(sem_t **fork, sem_t **sem)
{
	sem_post(*fork);
	sem_post(*sem);
	return (1);
}

int	one_philo(t_philo *philo)
{
	if (philo->data->n_philos > 1)
		return (0);
	if (philo->data->n_philos == 1)
		print_action(philo, YELLOW, R_FORK, 0);
	smart_sleep(philo->data->t_die);
	philo->data->state = DEAD;
	return (1);
}
