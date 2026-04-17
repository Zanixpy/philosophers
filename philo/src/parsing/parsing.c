/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:54:51 by omawele           #+#    #+#             */
/*   Updated: 2026/04/13 12:02:24 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

int	strcmp_int_limit(char *s)
{
	char	*int_max;
	int		size;

	int_max = "2147483647";
	size = ft_strlen(s);
	if (size <= 9)
		return (0);
	while (*int_max)
	{
		if (*int_max < *s)
			return (1);
		int_max++;
		s++;
	}
	return (0);
}

static int	check_args_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		if (strcmp_int_limit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	validator(t_data *data, int argc, char **argv)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (1);
	if (argc != 5 && argc != 6)
		return (error_args(1), 1);
	if (check_args_int(argc, argv))
		return (error_args(0), 1);
	data->size = ft_atoi(argv[1]);
	data->tto_die = ft_atoi(argv[2]);
	data->tto_eat = ft_atoi(argv[3]);
	data->tto_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->eat_count = ft_atoi(argv[5]);
	else
	{
		data->eat_count = 0;
	}
	if (data->size == 0)
		return (1);
	return (0);
}

static int	create_mutexes(pthread_mutex_t **print_mutex,
		pthread_mutex_t **stop_mutex)
{
	*print_mutex = malloc(sizeof(pthread_mutex_t));
	if (!(*print_mutex))
		return (1);
	if (pthread_mutex_init(*print_mutex, NULL) != 0)
		return (free(*print_mutex), 1);
	*stop_mutex = malloc(sizeof(pthread_mutex_t));
	if (!(*stop_mutex))
	{
		pthread_mutex_destroy(*print_mutex);
		free(*print_mutex);
		return (1);
	}
	if (pthread_mutex_init(*stop_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(*print_mutex);
		free(*print_mutex);
		return (free(*stop_mutex), 1);
	}
	return (0);
}

int	init_all(t_philo **philos, t_fork **forks, t_monitor **monitor,
		t_data *data)
{
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*stop_mutex;

	if (create_mutexes(&print_mutex, &stop_mutex))
		return (error_init(2));
	*forks = init_forks(data->size);
	if (!(*forks))
		return (free_mutex(&print_mutex), free_mutex(&stop_mutex),
			error_init(1));
	*philos = init_philosophers(data, *forks, &print_mutex, &stop_mutex);
	if (!(*philos))
		return (free_mutex(&print_mutex), free_mutex(&stop_mutex),
			free_forks(*forks, data->size), error_init(2));
	if (data->size == 1)
		return (0);
	*monitor = init_monitor(philos, data, &print_mutex, &stop_mutex);
	if (!(*monitor))
		return (clean(*forks, *philos, *monitor, data->size), error_init(3));
	return (0);
}
