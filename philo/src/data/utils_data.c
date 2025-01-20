/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:16:21 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/20 12:53:40 by danpalac         ###   ########.fr       */
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

void	print_dead(long long start_time, int dead_philo)
{
	printf("%s", RED);
	printf("[%lld] Philo [%d]  %s\n", get_time(NULL) - start_time, dead_philo,
		DIED);
	printf("%s", RESET);
}

int	one_philo(int t_to_die, int n_philos)
{
	long long	start_time;

	if (n_philos == 1)
	{
		start_time = get_time(NULL);
		printf("%s[%s%2lld%s] ", BLACK, BRIGHT_WHITE, (get_time(NULL)
				- start_time), BLACK);
		printf("%sPhilo [%s%d%s%s] ", BOLD_BLUE, BOLD_CYAN, 1, RESET,
			BOLD_BLUE);
		printf(" %s%s\n", YELLOW, R_FORK);
		printf(RESET);
		usleep(1000 * t_to_die);
		print_dead(start_time, 1);
		return (1);
	}
	return (0);
}
