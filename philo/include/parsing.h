/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:51:48 by omawele           #+#    #+#             */
/*   Updated: 2026/03/21 18:45:18 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "error.h"
# include "free.h"
# include "utils.h"

int			validator(t_data *data, int argc, char **argv);
int			init_all(t_philo **philos, t_fork **forks, t_monitor **monitor,
				t_data *data);
t_fork		*init_forks(int nb_forks);
t_monitor	*init_monitor(t_philo **philos, t_data *data,
				pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex);
t_philo		*init_philosophers(t_data *data, t_fork *forks,
				pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex);

#endif
