/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:28:52 by ssurilla          #+#    #+#             */
/*   Updated: 2023/05/05 18:01:09 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// calculate total nr tiles row * length
int	max_tiles(t_main *main, char *map)
{
	int	len;
	int	high;
	int	total;

	len = get_linelen(main);
	high = get_newline(map);
	total = len * high;
	return (total);
}

// checks for exit errors
int	check_exit_error(char *dup, t_main *main)
{
	int	count;

	count = 0;
	while (dup[count])
	{
		if (dup[count] == 'X')
		{
			if (dup[count - 1] == 'E' || dup[count + 1] == 'E' || dup[count
				+ get_linelen(main)] == 'E' || dup[count
				- get_linelen(main)] == 'E')
				return (1);
		}
		count++;
	}
	return (0);
}

// replace tiles to X innorder to move to empty space/coll
char	*first_rep(int ppos, char *dup, t_main *main)
{
	if (dup[ppos] == 'P')
	{
		if (dup[ppos - 1] == 'C' || dup[ppos - 1] == '0')
			dup[ppos - 1] = 'X';
		if (dup[ppos + 1] == 'C' || dup[ppos + 1] == '0')
			dup[ppos + 1] = 'X';
		if (dup[ppos - get_linelen(main)] == 'C' || dup[ppos
			- get_linelen(main)])
			dup[ppos - get_linelen(main)] = 'X';
		if (dup[ppos + get_linelen(main)] == 'C' || dup[ppos
			+ get_linelen(main) == '0'])
			dup[ppos + get_linelen(main)] = 'X';
	}
	return (dup);
}

// update X tiles next to X tiles
char	*check_and_rep(char *dup, t_main *main)
{
	int	count;

	count = 0;
	while (dup[count])
	{
		if (dup[count] == 'X')
		{
			if (dup[count - 1] == 'C' || dup[count - 1] == '0')
				dup[count - 1] = 'X';
			else if (dup[count + 1] == 'C' || dup[count + 1] == '0')
				dup[count + 1] = 'X';
			if (dup[count - get_linelen(main)] == 'C' || dup[count
				- get_linelen(main)] == '0')
				dup[count - get_linelen(main)] = 'X';
			if (dup[count + get_linelen(main)] == 'C' || dup[count
				+ get_linelen(main)] == '0')
				dup[count + get_linelen(main)] = 'X';
		}
		count++;
	}
	return (dup);
}
