/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:31:05 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/27 15:24:49 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_imgs(t_vars *vars)
{
	vars->img_arr = (t_img *)ft_calloc(11, sizeof(t_img));
	vars->imgs_created = 1;
	if (!vars->img_arr)
		return (1);
	if (!img_bg(vars))
		return (1);
	if (!img_collect(vars))
		return (1);
	if (!img_exit(vars))
		return (1);
	if (!img_wall(vars))
		return (1);
	if (!img_player_down(vars))
		return (1);
	if (!img_player_left(vars))
		return (1);
	if (!img_player_right(vars))
		return (1);
	if (!img_player_up(vars))
		return (1);
	return (0);
}

// display img from char pos(i=column & j=row) in nl
static void	help(size_t i, size_t j, int *pos, t_vars *vars)
{
	if (vars->nl[j * (vars->mem->cols + 1) + i] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_arr[0].img,
				pos[0], pos[1]);
	else if (vars->nl[j * (vars->mem->cols + 1) + i] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_arr[1].img,
				pos[0], pos[1]);
	else if (vars->nl[j * (vars->mem->cols + 1) + i] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_arr[2].img,
				pos[0], pos[1]);
	else if (vars->nl[j * (vars->mem->cols + 1) + i] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_arr[3].img,
				pos[0], pos[1]);
	else if (vars->nl[j * (vars->mem->cols + 1) + i] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_arr[4].img,
				pos[0], pos[1]);
}

int	print_init_img(t_vars *vars, t_stru mem)
{
	size_t i;
	size_t j;
	int pos[2];

	if (!init_imgs(vars))
		return (1);
	j = 0;
	pos[1] = 0;
	while (j < mem.rows)
	{
		i = 0;
		pos[0] = 0;
		while (i < mem.cols)
		{
			help(i, j, pos, vars);
			i++;
			pos[0] += vars->img_arr[1].width;
		}
		pos[1] += vars->img_arr[1].height;
		j++;
	}
	return (0);
}
