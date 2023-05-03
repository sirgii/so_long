/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:34:59 by ssurilla          #+#    #+#             */
/*   Updated: 2023/05/03 17:54:56 by ssurilla         ###   ########.fr       */
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
			mlx_put_image_to_window(main->mlx, main->win, main->sp.wall.img,
				i * 40, j * 40);
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
	i = (((main->map.maxheight * 40) - (main->map.mapheight * 40)) / 2);
	while (i < main->map.maxheight * 40)
	{
		j = (((main->map.maxlen * 40) - (main->map.maplen * 40)) / 2);
		while (j < main->map.maxlen * 40)
		{
			img_check(count, main, j, i);
			if (main->map.crab[count] == '\0')
				break ;
			if (main->map.crab[count] == '\n')
				j += 1000;
			j += 40;
			count++;
		}
		i += 40;
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
			"./textures/background.xpm", &main->sp.bg.imw, &main->sp.bg.imh);
	main->sp.player.img = mlx_xpm_file_to_image(main->mlx,
			"./textures/pldown.xpm", &main->sp.player.imw,
			&main->sp.player.imh);
	main->sp.collim.img = mlx_xpm_file_to_image(main->mlx,
			"./textures/collectcoin.xpm", &main->sp.collim.imw,
			&main->sp.collim.imh);
	main->sp.exit.img = mlx_xpm_file_to_image(main->mlx,
			"./textures/exit.xpm", &main->sp.exit.imw, &main->sp.exit.imh);
	main->sp.wall.img = mlx_xpm_file_to_image(main->mlx,
			"./textures/walls.xpm", &main->sp.wall.imw, &main->sp.wall.imh);
}
