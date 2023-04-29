/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:53:35 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/29 15:20:03 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

int is_exit(t_vars *vars, int x, int y)
{
    if (vars->nl[(y / TILE_HEIGHT) * (vars->mem->cols + 1)
        + (x / TILE_WIDTH)] == 'E')
    {
        if (vars->mem->collectible == 0)
            return (1);
        return (2);
    }
    return (0);
}

void    terminate_game(t_vars *vars, int trgb, char *str)
{
    mlx_clear_window(vars->mlx, vars->win);
    mlx_string_put(vars->mlx, vars->win, vars->mem->cols * TILE_WIDTH / 2,
        vars->mem->rows * TILE_HEIGHT / 2,
        trgb, str);
    vars->game_stat = 0;
}

void    check_finish(t_vars *vars, int x, int y)
{
    if (is_exit(vars, x, y) == 1)
        terminate_game(vars, create_trgb(255, 0, 255, 0), "Congratulations!");
    if (is_exit(vars, x, y) == 2)
        terminate_game(vars, create_trgb(255, 255, 0, 0), "Try again!");
}
