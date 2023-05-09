/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:27:18 by ssurilla          #+#    #+#             */
/*   Updated: 2023/05/08 15:12:03 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check init functions and valid map
void	init_error(t_main *main, int lines)
{
	int	init;

	init = 0;
	if (ascii_check(main->map.crab, 'P') == 1)
		init++;
	if (ascii_check(main->map.crab, 'E') == 1)
		init++;
	if (check_equal(main, lines, 0, 0) == 1)
		init++;
	if (fill_walls(main->map.crab, lines, 0, 1) == 1)
		init++;
	if (move_and_check(main) == 1)
		init++;
	if (init != 5)
	{
		ft_printf("Error\n Invalid Map, try another one.");
		close_prog(main);
	}
}

// main checker for all tiles
int	move_and_check(t_main *main)
{
	int		ppos;
	int		current;
	int		maxtile;
	char	*dup;

	current = 0;
	ppos = get_ppos(main);
	dup = ft_strdup(main->map.crab);
	maxtile = max_tiles(main, dup);
	dup = first_rep(ppos, dup, main);
	while (current < maxtile)
	{
		if (check_exit_error(dup, main) == 1)
		{
			free(dup);
			return (1);
		}
		dup = check_and_rep(dup, main);
		current++;
	}
	free(dup);
	return (0);
}

// rowlen check
int	check_equal(t_main *main, int lines, int currentline, int linelentot)
{
	int	linelencurr;
	int	count;

	currentline = 0;
	linelentot = get_linelen(main) - 1;
	count = 0;
	linelencurr = 0;
	while (currentline < lines)
	{
		while (main->map.crab[count])
		{
			if (main->map.crab[count] == '\n')
			{
				if (linelencurr != linelentot)
					return (0);
				count++;
				linelencurr = 0;
				break ;
			}
			count++;
			linelencurr++;
		}
		currentline++;
	}
	return (1);
}
