/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exithook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:43:24 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/28 16:20:05 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	red_x(t_vars *vars)
{
	exit_clean(vars);
	exit(1);
	return (0);
}

int	exithook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit_clean(vars);
		exit(1);
	}
	return (0);
}