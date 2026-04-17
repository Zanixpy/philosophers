/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:35:19 by omawele           #+#    #+#             */
/*   Updated: 2026/04/13 12:01:55 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	precise_sleep(t_philo *philo, size_t duration_ms)
{
	size_t	start;
	size_t	now;

	start = get_time_ms(philo->data.start_time);
	while (1)
	{
		if (should_stop(philo))
			break ;
		now = get_time_ms(philo->data.start_time);
		if (now - start >= duration_ms)
			break ;
		usleep(400);
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->locker);
	pthread_mutex_unlock(&philo->right_fork->locker);
}

int	should_stop(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(philo->stop_mutex);
	stop = philo->stop;
	pthread_mutex_unlock(philo->stop_mutex);
	return (stop);
}

void	print_state(t_philo *philo, int index, char *text)
{
	pthread_mutex_lock(philo->print_mutex);
	pthread_mutex_lock(philo->stop_mutex);
	if (!philo->stop)
		printf("%ld %d %s\n", get_time_ms(philo->data.start_time), index, text);
	pthread_mutex_unlock(philo->stop_mutex);
	pthread_mutex_unlock(philo->print_mutex);
}
