/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:08:49 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/25 19:01:01 by ssurilla         ###   ########.fr       */
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
# include <stdlib.h>

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
	char	*nl;
	t_stru	*mem;
	size_t	moves;
	int		pid;
	int		game_stat;
	int		imgs_created;
	int		count;
}			t_vars;

int	img_player_up(t_vars *vars);
int	img_player_down(t_vars *vars);
int	img_player_left(t_vars *vars);
int	img_player_right(t_vars *vars);
int	img_bg(t_vars *vars);
int	img_wall(t_vars *vars);
int	img_collect(t_vars *vars);
int	img_exit(t_vars *vars);
int init_imgs(t_vars *vars);
int	print_init_img(t_vars *vars, t_stru mem);
void	check_map_data(char *file_name, t_vars *vars);
void	exit_clean(t_vars *vars);
int middle_line(char *nl, t_stru *mem);
int last_line(char *nl, t_stru *mem);
int first_line(char *nl, t_stru *mem);
char    *ft_strjoin_2(char *s1, char *s2);
int fill_array(char *argv, char **nl, t_stru *mem);


#endif
