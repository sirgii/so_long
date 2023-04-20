/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:40:05 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/20 17:10:53 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int img_player_up(t_vars *vars)
{
    vars->img_arr[4].img = mlx_xpm_file_to_image(
        vars->mlx, "textures/plup.png", &vars->img_arr[4].width,
            &vars->img_arr[4]);
    if (!vars->img_arr[4].img)
        return (1); 
}