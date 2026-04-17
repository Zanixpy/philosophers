/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:09:38 by omawele           #+#    #+#             */
/*   Updated: 2026/04/13 12:07:01 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "error.h"
# include "utils.h"

void	*routine_philosophers(void *args);
void	*routine_philosopher(void *args);
void	*routine_monitor(void *args);

void	release_forks(t_philo *philo);
void	print_state(t_philo *philo, int index, char *text);

int		is_dead(t_monitor *monitor, int index);
int		check_eat_times(t_monitor *monitor, int is_count);
void	print_death(t_monitor *monitor, int index);
void	end_simulation(t_monitor *monitor);

void	psleep(t_philo *philo);
void	eat(t_philo *philo);
void	take_forks(t_philo *philo);

#endif