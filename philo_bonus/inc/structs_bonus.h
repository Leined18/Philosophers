#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

typedef struct philo
{
	int		id;
	int		*forks;
}			t_philo;

typedef struct s_data
{
	int		n;
	int		*forks;
}			t_data;

typedef struct s_memory
{
	t_data	*data;
	t_philo	*philos;
	int		ac;
	char	**av;
}			t_memory;

#endif // STRUCTS_BONUS_H