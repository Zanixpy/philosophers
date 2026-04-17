/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:16:55 by omawele           #+#    #+#             */
/*   Updated: 2026/04/10 13:18:35 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

static void	set_forks(t_philo *philo, t_fork *forks)
{
	if (philo->data.size == 1)
	{
		philo->left_fork = &forks[0];
		philo->right_fork = &forks[0];
		return ;
	}
	philo->left_fork = &forks[philo->index - 1];
	if (philo->index == philo->data.size)
		philo->right_fork = &forks[0];
	else
		philo->right_fork = &forks[philo->index];
}

static int	set_personnal_mutexes(t_philo *philo)
{
	if (pthread_mutex_init(&philo->lock_eat_count, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&philo->lock_last_meal, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->lock_eat_count);
		return (1);
	}
	return (0);
}

t_philo	*init_philosophers(t_data *data, t_fork *forks,
		pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex)
{
	t_philo			*philo;
	unsigned int	i;

	philo = malloc(data->size * sizeof(t_philo));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < data->size)
	{
		philo[i].index = i + 1;
		philo[i].data = *data;
		philo[i].print_mutex = *print_mutex;
		philo[i].stop_mutex = *stop_mutex;
		philo[i].stop = 0;
		philo[i].eat_count = 0;
		set_forks(&philo[i], forks);
		if (set_personnal_mutexes(&philo[i]))
			return (free_philos(philo, data->size), NULL);
		i++;
	}
	return (philo);
}
