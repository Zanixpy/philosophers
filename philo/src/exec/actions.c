/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:12:50 by omawele           #+#    #+#             */
/*   Updated: 2026/04/17 14:18:58 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	psleep(t_philo *philo)
{
	print_state(philo, philo->index, "is sleeping");
	precise_sleep(philo, philo->data.tto_sleep);
}

void	eat(t_philo *philo)
{
	print_state(philo, philo->index, "is eating");
	pthread_mutex_lock(&philo->lock_last_meal);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->lock_last_meal);
	precise_sleep(philo, philo->data.tto_eat);
	pthread_mutex_lock(&philo->lock_eat_count);
	if (philo->data.eat_count)
		philo->eat_count += 1;
	pthread_mutex_unlock(&philo->lock_eat_count);
}

void	take_forks(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->locker);
		print_state(philo, philo->index, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork->locker);
		print_state(philo, philo->index, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->locker);
		print_state(philo, philo->index, "has taken a fork");
		pthread_mutex_lock(&philo->left_fork->locker);
		print_state(philo, philo->index, "has taken a fork");
	}
}
