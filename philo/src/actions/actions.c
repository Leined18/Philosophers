#include "actions.h"

int	take_forks(t_philo *philo)
{
	if (get_global_state(philo->data))
		return (0);
	if (!lock_forks(philo))
		return (0);
	return (1);
}

int	eat(t_philo *philo)
{
	if (!take_forks(philo))
		return (0);
	if (!update_last_meal(philo, get_time(&philo->mutexes[TIME])))
		return (unlock_forks(philo), 0);
	if (!print_action(philo, GREEN, EATING, philo->data->t_eat))
		return (unlock_forks(philo), 0);
	take_meal(philo);
	return (unlock_forks(philo));
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

	if (get_global_state(philo->data))
		return (0);
	pthread_mutex_lock(&philo->mutexes[PRINT]);
	if (get_global_state(philo->data))
		return (pthread_mutex_unlock(&philo->mutexes[PRINT]), 0);
	time_elapsed = get_time(NULL) - philo->data->start_time;
	printf("%s[%s%2ld%s] ", BLACK, BRIGHT_WHITE, time_elapsed, BLACK);
	printf("%sPhilo [%s%d%s%s] ", BOLD_BLUE, BOLD_CYAN, philo->id, RESET,
		BOLD_BLUE);
	printf(" %s%s\n", color, action);
	printf(RESET);
	pthread_mutex_unlock(&philo->mutexes[PRINT]);
	smart_sleep(wait_time, philo->data);
	return (1);
}
