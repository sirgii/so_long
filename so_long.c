/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:54:06 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/29 16:17:13 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// free mem when terminated
void	exit_clean(t_vars *vars)
{
	if (vars->mem)
		free(vars->mem);
	if (vars->imgs_created)
		free(vars->img_arr);
	if (vars->nl)
		free(vars->nl);
}

static int	start_game(t_vars *vars)
{
	vars->moves = 0;
	vars->game_stat = 1;
	vars->pid = getpid();
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		exit_clean(vars);
		return (1);
	}
	vars->win = mlx_new_window(vars->mlx, 32 * vars->mem->cols, 32
			* vars->mem->rows, "So_Long");
	if (!vars->win || !print_init_img(vars, *vars->mem))
	{
		exit_clean(vars);
		return (1);
	}
	return (0);
}

void	check_map_data(char *file_name, t_vars *vars)
{
	int	i;

	i = ft_strlen(file_name) - 4;
	if (i <= 0)
	{
		ft_printf("Insert correct .ber file!\n");
		exit_clean(vars);
		exit(0);
	}
	if (ft_strncmp(&file_name[i], ".ber", 4) != 0)
	{
		ft_printf("Insert correct .ber file!\n");
		exit_clean(vars);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		ft_printf("Insert only one .ber file.\n");
		return (1);
	}
	check_map_data(argv[1], &vars);
	vars.mem = (t_stru *)ft_calloc(1, sizeof(t_stru));
	if (!vars.mem)
		return (1);
	if (!fill_array(argv[1], &vars.nl, vars.mem))
	{
		exit_clean(&vars);
		return (1);
	}
	if (!start_game(&vars))
		return (1);
	mlx_key_hook(vars.win, &key_hook, &vars);
	mlx_hook(vars.win, 17, 0, &red_x, &vars);
	mlx_loop(vars.mlx);
	exit_clean(&vars);
	return (0);
}
