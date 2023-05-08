/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:08:49 by ssurilla          #+#    #+#             */
/*   Updated: 2023/05/05 18:01:52 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 100

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_wall
{
	void		*img;
	char		*relative_path;
	int			imw;
	int			imh;
}				t_wall;

typedef struct s_bg
{
	void		*img;
	char		*relative_path;
	int			imw;
	int			imh;
}				t_bg;

typedef struct s_exit
{
	void		*img;
	char		*relative_path;
	int			imw;
	int			imh;
}				t_exit;

typedef struct s_collim
{
	void		*img;
	char		*relative_path;
	int			imw;
	int			imh;
}				t_collim;

typedef struct s_player
{
	void		*img;
	char		*relative_path;
	int			imw;
	int			imh;
}				t_player;

typedef struct s_textures
{
	t_exit		exit;
	t_bg		bg;
	t_wall		wall;
	t_collim	collim;
	t_player	player;
}				t_textures;

typedef struct s_coll
{
	int			amount;
	int			current;
}				t_coll;

typedef struct s_map
{
	char		*crab;
	int			maxheight;
	int			mapheight;
	int			maxlen;
	int			maplen;
	int			totallen;
	int			totalheight;
	int			ppos;
	int			moves;
	t_coll		coll;
}				t_map;

typedef struct s_main
{
	void		*mlx;
	void		*win;
	t_textures	sp;
	t_map		map;
}				t_main;

// init_img
void			first_rend(t_main *main);
int				rend_nextfr(t_main *main);
void			img_check(int counter, t_main *main, int j, int i);
void			rend_img(t_main *main);

// gets
int				get_linelen(t_main *main);
int				get_maph(char *map);
int				get_ppos(t_main *main);
int				get_collcount(t_main *main);

// init_win
int				keypress_han(int keysym, t_main *main);
int				close_prog(t_main *main);
void			win_init(t_main *main, char *map);

// map_check
char			*free_dict(char *buffer, char *buf);
char			*loadmap(int fd);
int				get_newline(char *map);
int				ascii_check(char *map, int symb);
int				fill_walls(char *map, int lines, int passed, int valid);

// movement
void			move_down(t_main *main);
void			move_up(t_main *main);
void			move_left(t_main *main);
void			move_right(t_main *main);
// void			movement(t_main *main, int dir);

// error check
void			init_error(t_main *main, int lines);
int				move_and_check(t_main *main);
// int				spread(t_main *main, char *map, int ppos);
int				check_equal(t_main *main, int lines, int currentline,
					int linelentot);

// error utils
int				max_tiles(t_main *main, char *map);
int				check_exit_error(char *dup, t_main *main);
char			*first_rep(int ppos, char *dup, t_main *main);
char			*check_and_rep(char *dup, t_main *main);

#endif
