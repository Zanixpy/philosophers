/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:12:19 by omawele           #+#    #+#             */
/*   Updated: 2026/04/10 13:22:32 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/free.h"

void	free_philos(t_philo *philos, int size)
{
	int	i;

	if (!philos)
		return ;
	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&philos[i].lock_last_meal);
		pthread_mutex_destroy(&philos[i].lock_eat_count);
		i++;
	}
	free(philos);
}

void	free_forks(t_fork *forks, int size)
{
	int	i;

	if (!forks)
		return ;
	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&forks[i].locker);
		i++;
	}
	free(forks);
}

void	free_monitor(t_monitor *monitor)
{
	if (monitor)
		free(monitor);
}

void	free_mutex(pthread_mutex_t **mutex)
{
	pthread_mutex_destroy(*mutex);
	free(*mutex);
}

void	clean(t_fork *forks, t_philo *philos, t_monitor *monitor, int size)
{
	free_mutex(&philos->print_mutex);
	free_mutex(&philos->stop_mutex);
	free_philos(philos, size);
	free_forks(forks, size);
	free_monitor(monitor);
}
