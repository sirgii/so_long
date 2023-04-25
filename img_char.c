/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:40:05 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/25 19:02:05 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	img_player_up(t_vars *vars)
{
	vars->img_arr[4].img = mlx_xpm_file_to_image(
		vars->mlx, "textures/plup.png", &vars->img_arr[4].width,
			&vars->img_arr[4].height);
	if (!vars->img_arr[4].img)
		return (1);
	vars->img_arr[4].img_data = (int *)mlx_get_data_addr(
		vars->img_arr[4].img, &vars->img_arr[4].bits_per_pixel,
			&vars->img_arr[4].line_length, &vars->img_arr[4].endian);
	if (!vars->img_arr[4].img_data)
		return (1);
	return (0);
}

int	img_player_down(t_vars *vars)
{
	vars->img_arr[5].img = mlx_xpm_file_to_image(
		vars->mlx, "textures/pldown.png", &vars->img_arr[5].width,
			&vars->img_arr[5].height);
	if (!vars->img_arr[5].img)
		return (1);
	vars->img_arr[5].img_data = (int *)mlx_get_data_addr(
		vars->img_arr[5].img, &vars->img_arr[5].bits_per_pixel,
			&vars->img_arr[5].line_length, &vars->img_arr[5].endian);
	if (!vars->img_arr[5].img_data)
		return (1);
	return (0);
}

int	img_player_left(t_vars *vars)
{
	vars->img_arr[6].img = mlx_xpm_file_to_image(
		vars->mlx, "textures/plleft.png", &vars->img_arr[6].width,
			&vars->img_arr[6].height);
	if (!vars->img_arr[6].img)
		return (1);
	vars->img_arr[6].img_data = (int *)mlx_get_data_addr(
		vars->img_arr[6].img, &vars->img_arr[6].bits_per_pixel,
			&vars->img_arr[6].line_length, &vars->img_arr[6].endian);
	if (!vars->img_arr[6].img_data)
		return (1);
	return (0);
}

int	img_player_right(t_vars *vars)
{
	vars->img_arr[7].img = mlx_xpm_file_to_image(
		vars->mlx, "textures/plright.png", &vars->img_arr[7].width,
			&vars->img_arr[7].height);
	if (!vars->img_arr[7].img)
		return (1);
	vars->img_arr[7].img_data = (int *)mlx_get_data_addr(
		vars->img_arr[7].img, &vars->img_arr[7].bits_per_pixel,
			&vars->img_arr[7], &vars->img_arr[7].endian);
	if (!vars->img_arr[7].img_data)
		return (1);
	return (0);
}
