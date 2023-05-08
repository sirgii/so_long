/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:59:03 by ssurilla          #+#    #+#             */
/*   Updated: 2023/05/03 18:43:16 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_main	*main;

	if (argc <= 1)
	{
		ft_printf("Error \n Invalid input(./so_long + .ber )");
		exit(1);
	}
	main = (t_main *)malloc(sizeof(t_main));
	main->mlx = mlx_init();
	main->win = mlx_new_window(main->mlx, 1920, 1090, "SO_LONG");
	win_init(main, argv[1]);
	mlx_hook(main->win, 2, 1L, keypress_han, main);
	mlx_hook(main->win, 17, 0, close_prog, main);
	mlx_loop_hook(main->mlx, rend_nextfr, main);
	mlx_loop(main->mlx);
	return (0);
}
