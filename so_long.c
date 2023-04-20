/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:54:06 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/20 16:23:32 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// free mem when terminated
void	exit_clean(t_vars *vars)
{
	if (vars->mem)
		free(vars->mem);
	if (vars->imgs_created)
		free(vars->img_arr);
	if (vars->map)
		free(vars->map);
}

static int	start_game(t_vars *vars)
{
	vars->moves = 0;
	vars->game_stat = 1;
	vars->pid = getpid();
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		exit_clean(vars);
		return (0);
	}
	vars->win = mlx_new_window(vars->mlx, 32 * vars->mem->cols, 32
			* vars->mem->rows, "So_Long");
	if (!vars->win || !print_initial_img(vars, *vars->mem))
	{
		exit_clean(vars);
		return (0);
	}
	return (1);
}
