/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:40:48 by ssurilla          #+#    #+#             */
/*   Updated: 2023/05/05 18:03:42 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// if not a wall, check conditions for symbols
void	move_down(t_main *main)
{
	if (main->map.crab[main->map.ppos + get_linelen(main)] != '1')
	{
		if (main->map.crab[main->map.ppos + get_linelen(main)] == '0')
		{
			main->map.crab[main->map.ppos + get_linelen(main)] = 'P';
			main->map.crab[main->map.ppos] = '0';
			main->map.crab += get_linelen(main);
		}
		else if (main->map.crab[main->map.ppos + get_linelen(main)] == 'C')
		{
			main->map.crab[main->map.ppos + get_linelen(main)] = 'P';
			main->map.crab[main->map.ppos] = '0';
			main->map.coll.current++;
			main->map.crab += get_linelen(main);
		}
		else if (main->map.crab[main->map.ppos + get_linelen(main)] == 'E')
		{
			if (main->map.coll.amount == main->map.coll.current)
				close_prog(main);
			else
				main->map.moves--;
		}
		ft_printf("MOVES: %i\n", main->map.moves++);
	}
}

void	move_up(t_main *main)
{
	if (main->map.crab[main->map.ppos + get_linelen(main)] != '1')
	{
		if (main->map.crab[main->map.ppos + get_linelen(main)] == '0')
		{
			main->map.crab[main->map.ppos + get_linelen(main)] = 'P';
			main->map.crab[main->map.ppos] = '0';
			main->map.crab += get_linelen(main);
		}
		else if (main->map.crab[main->map.ppos + get_linelen(main)] == 'C')
		{
			main->map.crab[main->map.ppos + get_linelen(main)] = 'P';
			main->map.crab[main->map.ppos] = '0';
			main->map.coll.current++;
			main->map.crab += get_linelen(main);
		}
		else if (main->map.crab[main->map.ppos + get_linelen(main)] == 'E')
		{
			if (main->map.coll.amount == main->map.coll.current)
				close_prog(main);
			else
				main->map.moves--;
		}
		ft_printf("MOVES: %i\n", main->map.moves++);
	}
}

void	move_right(t_main *main)
{
	if (main->map.crab[main->map.ppos + get_linelen(main)] != '1')
	{
		if (main->map.crab[main->map.ppos + get_linelen(main)] == '0')
		{
			main->map.crab[main->map.ppos + get_linelen(main)] = 'P';
			main->map.crab[main->map.ppos] = '0';
			main->map.crab += get_linelen(main);
		}
		else if (main->map.crab[main->map.ppos + get_linelen(main)] == 'C')
		{
			main->map.crab[main->map.ppos + get_linelen(main)] = 'P';
			main->map.crab[main->map.ppos] = '0';
			main->map.coll.current++;
			main->map.crab += get_linelen(main);
		}
		else if (main->map.crab[main->map.ppos + get_linelen(main)] == 'E')
		{
			if (main->map.coll.amount == main->map.coll.current)
				close_prog(main);
			else
				main->map.moves--;
		}
		ft_printf("MOVES: %i\n", main->map.moves++);
	}
}

void	move_left(t_main *main)
{
	if (main->map.crab[main->map.ppos + get_linelen(main)] != '1')
	{
		if (main->map.crab[main->map.ppos + get_linelen(main)] == '0')
		{
			main->map.crab[main->map.ppos + get_linelen(main)] = 'P';
			main->map.crab[main->map.ppos] = '0';
			main->map.crab += get_linelen(main);
		}
		else if (main->map.crab[main->map.ppos + get_linelen(main)] == 'C')
		{
			main->map.crab[main->map.ppos + get_linelen(main)] = 'P';
			main->map.crab[main->map.ppos] = '0';
			main->map.coll.current++;
			main->map.crab += get_linelen(main);
		}
		else if (main->map.crab[main->map.ppos + get_linelen(main)] == 'E')
		{
			if (main->map.coll.amount == main->map.coll.current)
				close_prog(main);
			else
				main->map.moves--;
		}
		ft_printf("MOVES: %i\n", main->map.moves++);
	}
}
