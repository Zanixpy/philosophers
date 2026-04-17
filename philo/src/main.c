/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:21 by omawele           #+#    #+#             */
/*   Updated: 2026/04/10 15:44:38 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	join_threads(t_philo *philos, t_monitor *monitor, int size)
{
	int	i;

	i = 0;
	if (pthread_join(monitor->tid, NULL) != 0)
		return (1);
	while (i < size)
	{
		if (pthread_join(philos[i].tid, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	create_multi_threads(t_philo *philos, t_monitor *monitor, int size)
{
	int	i;

	i = 0;
	monitor->data.start_time = get_time();
	while (i < size)
	{
		philos[i].data.start_time = monitor->data.start_time;
		philos[i].last_meal_time = monitor->data.start_time;
		if (pthread_create(&philos[i].tid, NULL, &routine_philosophers,
				(void *)&philos[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_create(&monitor->tid, NULL, &routine_monitor,
			(void *)monitor) != 0)
		return (1);
	if (join_threads(philos, monitor, size))
		return (1);
	return (0);
}

int	create_one_thread(t_philo *philos)
{
	philos[0].data.start_time = get_time();
	if (pthread_create(&philos[0].tid, NULL, &routine_philosopher,
			(void *)&philos[0]) != 0)
		return (1);
	if (pthread_join(philos[0].tid, NULL) != 0)
		return (1);
	return (0);
}

int	start_simulation(t_philo *philos, t_monitor *monitor, int size)
{
	if (size == 1)
	{
		if (create_one_thread(philos))
			return (1);
	}
	else
	{
		if (create_multi_threads(philos, monitor, size))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fork		*forks;
	t_philo		*philos;
	t_monitor	*monitor;
	t_data		data;

	if (validator(&data, argc, argv))
		return (ERRARGS);
	forks = NULL;
	philos = NULL;
	monitor = NULL;
	if (init_all(&philos, &forks, &monitor, &data))
		return (ERRINIT);
	if (start_simulation(philos, monitor, data.size))
		return (clean(forks, philos, monitor, data.size), ERRTHREAD);
	return (clean(forks, philos, monitor, data.size), EXIT_SUCCESS);
}
