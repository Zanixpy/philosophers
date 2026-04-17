/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:09:17 by omawele           #+#    #+#             */
/*   Updated: 2026/04/13 12:01:58 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	*routine_philosophers(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->index % 2 == 0)
		precise_sleep(philo, philo->data.tto_eat / 2);
	if (philo->index == philo->data.size && philo->data.size % 2 != 0)
		precise_sleep(philo, philo->data.tto_eat);
	while (!should_stop(philo))
	{
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		psleep(philo);
		print_state(philo, philo->index, "is thinking");
		usleep(500);
	}
	return ((void *)0);
}

void	*routine_philosopher(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(&philo->left_fork->locker);
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d has taken a fork\n", get_time_ms(philo->data.start_time),
		philo->index);
	pthread_mutex_unlock(philo->print_mutex);
	pthread_mutex_unlock(&philo->left_fork->locker);
	precise_sleep(philo, philo->data.tto_die);
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d died\n", get_time_ms(philo->data.start_time), philo->index);
	pthread_mutex_unlock(philo->print_mutex);
	return ((void *)0);
}
