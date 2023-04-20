/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:08:49 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/20 16:23:56 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

# define TILE_WIDTH 32
# define TILE_HEIGHT 32

# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0

typedef struct s_stru
{
	size_t	memory;
	size_t	cols;
	size_t	rows;
	size_t	exit;
	size_t	collectible;
	size_t	ppos;
}			t_stru;

typedef struct s_img
{
	void	*img;
	int		*img_data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}			t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	*img_arr;
	char	*map;
	t_stru	*mem;
	size_t	moves;
	int		pid;
	int		game_stat;
	int		imgs_created;
	int		count;
}			t_vars;

#endif
