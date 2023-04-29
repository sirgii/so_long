/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:50:15 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/29 15:12:24 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	key_limits(t_vars *vars, int x, int y)
{
	if (vars->nl[(y / TILE_HEIGHT) * (vars->mem->cols + 1) + (x
			/ TILE_WIDTH)] == '1')
		return (0);
	else if (vars->nl[(y / TILE_HEIGHT) * (vars->mem->cols + 1) + (x
				/ TILE_WIDTH)] == 'C')
	{
		vars->mem->collectible--;
		vars->nl[(y / TILE_HEIGHT) * (vars->mem->cols + 1) + (x
				/ TILE_WIDTH)] = '0';
	}
	return (1);
}

static void	init_vars(t_vars *vars, int *x, int *y)
{
	*x = find_piece('P', 'x', vars) * TILE_WIDTH;
	*y = find_piece('P', 'y', vars) * TILE_HEIGHT;
}

int	key_hook(int keycode, t_vars *vars)
{
	static int	x;
	static int	y;

	if (!x && !y)
		init_vars(vars, &x, &y);
	exithook(keycode, vars);
	if (vars->game_stat == 0)
		return (0);
	else if (keycode == UP && key_limits(vars, x, y - TILE_HEIGHT) == 1)
		up_kc(vars, &x, &y);
	else if (keycode == DOWN && key_limits(vars, x, y + TILE_HEIGHT) == 1)
		down_kc(vars, &x, &y);
	else if (keycode == LEFT && key_limits(vars, x - TILE_WIDTH, y) == 1)
		left_kc(vars, &x, &y);
	else if (keycode == RIGHT && key_limits(vars, x + TILE_WIDTH, y) == 1)
		right_kc(vars, &x, &y);
	check_finish(vars, x, y);
	return (0);
}
