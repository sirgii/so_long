/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:05:27 by ssurilla          #+#    #+#             */
/*   Updated: 2023/05/03 14:46:46 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_linelen(t_main *main)
{
	int	count;

	count = 0;
	while (main->map.crab[count])
	{
		if (main->map.crab[count] == '\n')
		{
			count++;
			break ;
		}
		count++;
	}
	return (count);
}

int	get_maph(char *map)
{
	int	count;
	int	pos;

	count = 0;
	pos = 0;
	while (map[pos])
	{
		if (map[count] == '\n')
			count++;
		pos++;
	}
	return (count);
}

int	get_ppos(t_main *main)
{
	int	pos;

	pos = 0;
	while (main->map.crab[pos])
	{
		if (main->map.crab[pos] == 'P')
			return (pos);
		pos++;
	}
	return (0);
}

int	get_collcount(t_main *main)
{
	int	count;
	int	pos;

	count = 0;
	pos = 0;
	while (main->map.crab[pos])
	{
		if (main->map.crab[pos] == 'C')
			count++;
		pos++;
	}
	return (count);
}
