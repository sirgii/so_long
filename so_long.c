/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:54:06 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/18 15:54:13 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Pixels input
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render_next_frame(void *s_vars);

int	main(void)
{
	t_vars	img;
	t_vars	vars;
	t_vars	*mlx;
	t_vars	*win;

	mlx = mlx_init();
    win = mlx_new_window(mlx,  640, 480, "So long");
	img.img = mlx_new_image(mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_hook(vars.addr, 2, 1L<<0, close, &vars);
	mlx_key_hook(vars.addr, key_hook, &vars);
	mlx_loop_hook(mlx, render_next_frame, win);
    mlx_loop(mlx);
}
