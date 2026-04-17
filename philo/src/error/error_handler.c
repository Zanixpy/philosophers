/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:48:06 by omawele           #+#    #+#             */
/*   Updated: 2026/04/13 12:04:50 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"

void	error_args(int code)
{
	if (code)
		ft_putstr_fd("format: [nb_philos] [tto_die] [tto_eat] [tto_sleep]\n",
			2);
	else
		ft_putstr_fd("args: all values must be int positive integer\n", 2);
}

int	error_init(int code)
{
	if (code == 1)
		ft_putstr_fd("malloc: error occured in the forks initialization\n", 2);
	else if (code == 2)
		ft_putstr_fd("malloc: error occured in the philos initialization\n", 2);
	else if (code == 3)
		ft_putstr_fd("malloc: error occured in the monitor initialization\n",
			2);
	return (1);
}
