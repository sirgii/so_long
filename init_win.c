/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:36:59 by ssurilla          #+#    #+#             */
/*   Updated: 2023/05/03 18:01:19 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int				keypress_han(int keysym, t_main *main)
{
    if (keysym == 0xff1b)
        close_prog(main);
    else if (keysym == 115)
        move_down(main);
    else if (keysym == 119)
        move_up(main);
    else if (keysym == 100)
        move_right(main);
    else if (keysym == 97)
        move_left(main);
    return (0);
}

void    free_map(t_main *main)
{
    free(main->map.crab);
    free(main->sp.bg.img);
    free(main->sp.exit.img);
    free(main->sp.collim.img);
    free(main->sp.player.img);
    free(main->sp.wall.img);
}

void    free_window(t_main *main)
{
    free(main->mlx);
    free(main->win);
    free(main);
}

int	close_prog(t_main *main)
{
	mlx_destroy_display(main->mlx);
	exit(0);
	return (0);
}

void	win_init(t_main *main, char *map)
{
	int		fd;
	char	*temp;
	char	*map2;
	int		nls;

	fd = open(map, O_RDONLY);
	temp = loadmap(fd);
	map2 = ft_strdup(temp);
	main->map.crab = map2;
	main->map.maxlen = 34;
	main->map.maxheight = 17;
	rend_img(main);
	first_rend(main);
	nls = get_newline(map2) + 1;
	init_error(main, nls);
	close(fd);
	free(temp);
	main->map.mapheight = get_maph(main->map.crab);
	main->map.moves = 1;
	main->map.maplen = get_linelen(main);
    main->map.ppos = get_ppos(main);
    main->map.coll.amount = get_collcount(main);
    main->map.coll.current = 0;
}
