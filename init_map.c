/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:44:48 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/25 18:56:30 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_temp(char *temp)
{
	if (temp)
		free(temp);
}

static int	read_line(char **nl, int fd, t_stru *mem, char **temp)
{
	*temp = get_next_line(fd);
	if (*temp)
	{
		if (!middle_line(*temp, mem))
			return (1);
		*nl = ft_strjoin_2(*nl, *temp);
	}
	return (0);
}

static int	check_first(char **nl, int fd, t_stru *mem)
{
	*nl = get_next_line(fd);
	if (!*nl || !first_line(*nl, mem))
		return (1);
	return (0);
}

static int	check_following(char **nl, int fd, t_stru *mem)
{
	char *temp;

    temp = NULL;
    if (!read_line(nl, fd, mem, &temp))
    {
        free_temp(temp);
        return (1);
    }
    while (temp)
    {
        free (temp);
        if (!read_line(nl, fd, mem, &temp))
        {
            free(temp);
            return (1);
        }
    }
    free(temp);
    if (!last_line(&nl[0][(mem->rows - 1) * (mem-> cols + 1)], mem))
        return (1);
    return (0);
}

int fill_array(char *argv, char **nl, t_stru *mem)
{
    int fd;

    fd = open(argv, O_RDONLY);
    if (fd < 0)
        return (1);
    if (!check_first(nl, fd, mem))
    {
        close(fd);
        return (1);
    }
    if (!check_following(nl, fd, mem))
    {
        close(fd);
        return (1);
    }
    if (close(fd) < 0)
        return (1);
    return (0);
}