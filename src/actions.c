// src/actions.c
#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken the left fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken the right fork");
}

void	eat(t_philo *philo)
{
	print_action(philo, "is eating");
	philo->last_meal = get_current_time();
	usleep(philo->data->t_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleep_philo(t_philo *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->data->t_sleep);
}

void	think(t_philo *philo)
{
	print_action(philo, "is thinking");
}

void	print_action(t_philo *philo, const char *action)
{
	pthread_mutex_lock(&philo->data->print);
	printf("(%ld) %d %s\n", get_current_time(), philo->id, action);
	pthread_mutex_unlock(&philo->data->print);
}