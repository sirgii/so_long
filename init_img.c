/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:34:59 by ssurilla          #+#    #+#             */
/*   Updated: 2023/05/08 17:32:14 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// render bg
void	first_rend(t_main *main)
{
	int	i;
	int	j;

	j = 0;
	while (j <= main->map.mapheight)
	{
		i = 0;
		while (i <= main->map.maplen)
		{
			mlx_put_image_to_window(main->mlx, main->win, main->sp.bg.img,
				i * 32, j * 32);
			i++;
		}
		j++;
	}
}

// render actual map
int	rend_nextfr(t_main *main)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0; // (((main->map.maxheight * 32) - (main->map.mapheight * 32)) / 2);
	while (i <  main->map.maxheight * 32)
	{
		j = 0; // (((main->map.maxlen * 32) - (main->map.maplen * 32)) / 2);
		while (j < main->map.maxlen * 32)
		{
			img_check(count, main, j, i);
			if (main->map.crab[count] == '\0')
				break ;
			if (main->map.crab[count] == '\n')
				j += 1000;
			j += 32;
			count++;
		}
		i += 32;
	}
	return (0);
}

// img to spec position
void	img_check(int counter, t_main *main, int j, int i)
{
	if (main->map.crab[counter] == '0')
		mlx_put_image_to_window(main->mlx, main->win, main->sp.bg.img, j, i);
	else if (main->map.crab[counter] == 'P')
		mlx_put_image_to_window(main->mlx, main->win, main->sp.player.img,
			j, i);
	else if (main->map.crab[counter] == 'C')
		mlx_put_image_to_window(main->mlx, main->win, main->sp.collim.img,
			j, i);
	else if (main->map.crab[counter] == 'E')
		mlx_put_image_to_window(main->mlx, main->win, main->sp.exit.img, j, i);
	else if (main->map.crab[counter] == '1')
		mlx_put_image_to_window(main->mlx, main->win, main->sp.wall.img, j, i);
}

//  file directory
void	rend_img(t_main *main)
{
	main->sp.bg.img = mlx_xpm_file_to_image(main->mlx,
			"./textures/bg.xpm", &main->sp.bg.imw, &main->sp.bg.imh);
	main->sp.player.img = mlx_xpm_file_to_image(main->mlx,
			"./textures/player.xpm", &main->sp.player.imw,
			&main->sp.player.imh);
	main->sp.collim.img = mlx_xpm_file_to_image(main->mlx,
			"./textures/coins.xpm", &main->sp.collim.imw,
			&main->sp.collim.imh);
	main->sp.exit.img = mlx_xpm_file_to_image(main->mlx,
			"./textures/exit.xpm", &main->sp.exit.imw, &main->sp.exit.imh);
	main->sp.wall.img = mlx_xpm_file_to_image(main->mlx,
			"./textures/walls.xpm", &main->sp.wall.imw, &main->sp.wall.imh);
}
