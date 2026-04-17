/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:16:29 by omawele           #+#    #+#             */
/*   Updated: 2026/03/14 18:00:31 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "utils.h"

void	free_philos(t_philo *philos, int size);
void	free_forks(t_fork *forks, int size);
void	free_monitor(t_monitor *monitor);
void	free_mutex(pthread_mutex_t **mutex);
void	clean(t_fork *forks, t_philo *philos, t_monitor *monitor, int size);

#endif