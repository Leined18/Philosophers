/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:57:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 09:56:48 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	print_status(t_philo *philo, const char *color, const char *action)
{
	long long	time_elapsed;

	time_elapsed = get_time() - philo->data->start_time;
	printf("%s[%lld] %sPhilo [%d] %s\n", color, time_elapsed, philo->id,
		action);
}

int	safe_print(t_philo *philo, const char *color, const char *action)
{
	sem_wait(philo->data->print);
	print_status(philo, color, action);
	sem_post(philo->data->print);
	return (1);
}
