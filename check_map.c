/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:19:28 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/25 19:05:52 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check content for walls
int	first_line(char *nl, t_stru *mem)
{
	size_t	i;

	i = 0;
	if (!nl)
	{
		ft_printf("Map os empty!\n");
		return (1);
	}
	while (i < ft_strlen(nl))
	{
		if (nl[i] != '1' && nl[i] != '\n')
		{
			ft_printf("Walls must surround the map!\n");
			return (1);
		}
		i++;
	}
	if (nl[i - 1] == '1')
		mem->cols = i;
	else
		mem->cols = i - 1;
	mem->rows++;
	return (0);
}

static int	pos_finder(char *nl)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(nl))
	{
		if (nl[i] != '1' && nl[i] != '\n')
		{
			ft_printf("Walls must surround the map\n");
			return (1);
		}
		i++;
	}
	return (i);
}

int	last_line(char *nl, t_stru *mem)
{
	size_t	i;

	i = pos_finder(nl);
	if (!i)
		return (1);
	if ((nl[i - 1] == '1' && i != mem->cols) || (i - 1) != mem->cols)
	{
		ft_printf("Map is not rectangular!");
		return (1);
	}
	if (mem->exit < 1 || mem->collectible < 1 || mem->sp < 1)
	{
		ft_printf("Map needs at least one exit,");
		ft_printf(" one collectible and one player position!\n");
		return (1);
	}
	if (mem->sp > 1)
	{
		ft_printf("Not more than one starting position allowed");
		return (1);
	}
	return (0);
}

static int	check_format(char c, t_stru *mem)
{
	if (c == 'C')
		mem->collectible++;
	else if (c == 'E')
		mem->exit++;
	else if (c == 'P')
		mem->ppos++;
	else if (c != '0' && c != '\n')
	{
		ft_printf("Invalid map symbol on line %zu\n", mem->rows);
		return (1);
	}
	return (0);
}

int	middle_line(char *nl, t_stru *mem)
{
	size_t i;

	i = 0;
	mem->rows++;
	while (i < ft_strlen(nl))
	{
		if (!check_format(nl[i], mem))
			return (1);
		i++;
	}
	if ((nl[0] != '1') || (nl[i - 1] != '1' && nl[i - 2] != '1'))
	{
		ft_printf("Walls must surround the map!\n");
		return (1);
	}
	if ((nl[i - 1] == '1' && i != mem->cols) || (i - 1) != mem->cols)
	{
		ft_printf("Map is not rectangular!\n");
		return (1);
	}
	return (0);
}