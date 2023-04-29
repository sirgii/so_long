/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_textu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:40:33 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/27 15:20:53 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	img_bg(t_vars *vars)
{
	vars->img_arr[0].img = mlx_xpm_file_to_image(
		vars->mlx, "textures/background.png", &vars->img_arr[0].width,
			&vars->img_arr[0].height);
	if (!vars->img_arr[0].img)
		return (1);
	vars->img_arr[0].img_data = (int *)mlx_get_data_addr(
		vars->img_arr[0].img, &vars->img_arr[0].bits_per_pixel,
			&vars->img_arr[0].line_length, &vars->img_arr[0].endian);
	if (!vars->img_arr[0].img_data)
		return (1);
	return (0);
}

int	img_wall(t_vars *vars)
{
	vars->img_arr[1].img = mlx_xpm_file_to_image(
		vars->mlx, "textures/walls.png", &vars->img_arr[1].width,
			&vars->img_arr[1].height);
	if (!vars->img_arr[1].img)
		return (1);
	vars->img_arr[1].img_data = (int *)mlx_get_data_addr(
		vars->img_arr[1].img, &vars->img_arr[1].bits_per_pixel,
			&vars->img_arr[1].line_length, &vars->img_arr[1].endian);
	if (!vars->img_arr[1].img_data)
		return (1);
	return (0);
}

int	img_collect(t_vars *vars)
{
	vars->img_arr[2].img = mlx_xpm_file_to_image(
		vars->mlx, "textures/collectcoin.png", &vars->img_arr[2].width,
			&vars->img_arr[2].height);
	if (!vars->img_arr[2].img)
		return (1);
	vars->img_arr[2].img_data = (int *)mlx_get_data_addr(
		vars->img_arr[2].img, &vars->img_arr[2].bits_per_pixel,
			&vars->img_arr[2].line_length, &vars->img_arr[2].endian);
	if (!vars->img_arr[2].img_data)
		return (1);
	return (0);
}

int	img_exit(t_vars *vars)
{
	vars->img_arr[3].img = mlx_xpm_file_to_image(
		vars->mlx, "textures/exit.png", &vars->img_arr[3].width,
			&vars->img_arr[3].height);
	if (!vars->img_arr[3].img)
		return (1);
	vars->img_arr[3].img_data = (int *)mlx_get_data_addr(
		vars->img_arr[3].img, &vars->img_arr[3].bits_per_pixel,
			&vars->img_arr[3].line_length, &vars->img_arr[3].endian);
	if (!vars->img_arr[3].img_data)
		return (1);
	return (0);
}
