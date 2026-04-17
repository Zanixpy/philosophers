/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:32:40 by omawele           #+#    #+#             */
/*   Updated: 2026/03/21 17:32:54 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

t_fork	*init_forks(int nb_forks)
{
	t_fork	*forks;
	int		i;

	forks = malloc(nb_forks * sizeof(t_fork));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nb_forks)
	{
		if (pthread_mutex_init(&forks[i].locker, NULL) != 0)
			return (free_forks(forks, i), NULL);
		i++;
	}
	return (forks);
}
