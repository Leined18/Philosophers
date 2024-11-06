/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:25:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/06 10:43:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions_bonus.h"

int	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		if (!fork_up(philo, &philo->left_fork, L_FORK))
			return (0);
		if (!fork_up(philo, &philo->right_fork, R_FORK))
			return (fork_down(&philo->left_fork), 0);
	}
	else
	{
		if (!fork_up(philo, &philo->right_fork, R_FORK))
			return (0);
		if (!fork_up(philo, &philo->left_fork, L_FORK))
			return (fork_down(&philo->right_fork), 0);
	}
	return (1);
}

int	eat(t_philo *philo)
{
	if (!take_forks(philo))
		return (0);
	philo->last_meal = get_time();
	if (!print_action(philo, GREEN, EATING, philo->data->t_eat))
		return (fork_down(&philo->right_fork), fork_down(&philo->left_fork), 0);
	if (!is_alive(philo->data))
		return (fork_down(&philo->right_fork), fork_down(&philo->left_fork), 0);
	if (philo->meals)
		philo->meals--;
	return (fork_down(&philo->right_fork), fork_down(&philo->left_fork));
}

int	sleep_philo(t_philo *philo)
{
	if (!print_action(philo, BLUE, SLEEPING, philo->data->t_sleep))
		return (0);
	return (1);
}

int	think(t_philo *philo)
{
	if (!print_action(philo, PURPLE, THINKING, 0))
		return (0);
	return (1);
}

int	print_action(t_philo *philo, const char *color, const char *action,
		long wait_time)
{
	long long	time_elapsed;

	if (philo->data->state)
		return (0);
	sem_wait(philo->data->print_sem);
	time_elapsed = get_time() - philo->start_time;
	printf("%s[%s%2lld%s] ", BLACK, BRIGHT_WHITE, time_elapsed, BLACK);
	printf("%sPhilo [%s%d%s%s] ", BOLD_BLUE, BOLD_CYAN, philo->id, RESET,
		BOLD_BLUE);
	printf(" %s%s\n", color, action);
	printf(RESET);
	sem_post(philo->data->print_sem);
	if (wait_time > 0)
	{
		if (!smart_sleep(wait_time, philo))
			return (0);
	}
	if (philo->data->state)
		return (0);
	return (1);
}
