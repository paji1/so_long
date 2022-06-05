/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:42 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/05 06:37:24 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



static int game(t_vars *vars)
{
	// mlx_hook(vars->win_ptr , KeyPress,KeyPressMask , keys ,vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.player.down ,vars->player.x * 30 , \
					vars->player.y * 30);
	mlx_expose_hook(vars->win_ptr, draw_map, vars);
	mlx_hook(vars->win_ptr, KeyPress, KeyPressMask, key_handler, vars);
	mlx_hook(vars->win_ptr, 17,1L, exit_game, vars);
	mlx_loop(vars->mlx_ptr);
}

int main(int ac, char  **av)
{
	t_mapline		*lines;
	static t_mobs	mobs;
	t_vars			vars;

	parse(ac, av, &lines, &mobs);
	game_init(&vars, &mobs, &lines);
	game(&vars);
	return exit_game(&vars, EXIT_SUCCESS),0;
}
