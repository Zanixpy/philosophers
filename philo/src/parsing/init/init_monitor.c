/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:33:22 by omawele           #+#    #+#             */
/*   Updated: 2026/04/10 13:18:40 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

t_monitor	*init_monitor(t_philo **philos, t_data *data,
		pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex)
{
	t_monitor	*monitor;

	monitor = malloc(sizeof(t_monitor));
	if (!monitor)
		return (NULL);
	monitor->philos = *philos;
	monitor->data = *data;
	monitor->print_mutex = *print_mutex;
	monitor->stop_mutex = *stop_mutex;
	return (monitor);
}
