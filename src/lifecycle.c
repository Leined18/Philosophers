#include "philosophers.h"

int	is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	if (get_current_time() - philo->last_meal > philo->data->t_die)
	{
		printf("philo [%d] died\n", philo->id);
		philo->data->stop_simulation = 1;
		pthread_mutex_unlock(&philo->data->print);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->print);
	return (1);
}

void	lifecycle(t_philo *philo)
{
	take_forks(philo);
	eat(philo);
	sleep_philo(philo);
	think(philo);
}
