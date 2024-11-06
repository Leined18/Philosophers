#include "actions.h"

int	take_forks(t_philo *philo)
{
	if (philo->data->state)
		return (0);
	if (!lock_forks(philo))
		return (0);
	if (philo->data->state)
		return (0);
	return (1);
}

int	eat(t_philo *philo)
{
	if (!take_forks(philo))
		return (0);
	philo->last_meal = get_time();
	if (!print_action(philo, GREEN, EATING, philo->data->t_eat))
		return (unlock_forks(philo, 0));
	if (philo->meals)
		philo->meals--;
	if (philo->id % 2)
		return (unlock_forks(philo, 1));
	return (unlock_forks(philo, 1));
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
	long	time_elapsed;

	if (philo->data->state)
		return (0);
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->state)
		return (pthread_mutex_unlock(&philo->data->print), 0);
	time_elapsed = get_time() - philo->data->start_time;
	printf("%s[%s%2ld%s] ", BLACK, BRIGHT_WHITE, time_elapsed, BLACK);
	printf("%sPhilo [%s%d%s%s] ", BOLD_BLUE, BOLD_CYAN, philo->id, RESET,
		BOLD_BLUE);
	printf(" %s%s\n", color, action);
	printf(RESET);
	pthread_mutex_unlock(&philo->data->print);
	if (wait_time > 0)
		smart_sleep(wait_time, philo);
	return (1);
}
