/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:25:29 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/28 18:56:07 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up_kc(t_vars *vars, int *x, int *y)
{
	put_background(vars, *x, *y);
	*y -= TILE_HEIGHT;
	move_player(vars, *x, *y, 4);
}

void	left_kc(t_vars *vars, int *x, int *y)
{
	put_background(vars, *x, *y);
	*x -= TILE_WIDTH;
	move_player(vars, *x, *y, 6);
}

void	down_kc(t_vars *vars, int *x, int *y)
{
	put_background(vars, *x, *y);
	*y += TILE_HEIGHT;
	move_player(vars, *x, *y, 5);
}

void	right_kc(t_vars *vars, int *x, int *y)
{
	put_background(vars, *x, *y);
	*x += TILE_WIDTH;
	move_player(vars, *x, *y, 7);
}
