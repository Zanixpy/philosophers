/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:48:42 by omawele           #+#    #+#             */
/*   Updated: 2026/04/13 12:06:57 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "utils.h"
# define ERRARGS 2
# define ERRINIT 3
# define ERRTHREAD 4

void	error_args(int code);
int		error_init(int code);

#endif