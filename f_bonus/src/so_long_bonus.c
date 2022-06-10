/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:47:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 11:40:49 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	game(t_vars *vars)
{
	vars->enemy = NULL;
	mlx_expose_hook(vars->win_ptr, draw_map, vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.player.down, vars->player.x * 30, \
					vars->player.y * 30);
	mlx_hook(vars->win_ptr, KEYPRESS, KEYPRESSMASK, key_handler, vars);
	mlx_hook(vars->win_ptr, 17, BMASK, exit_game, vars);
	mlx_loop_hook(vars->mlx_ptr, enemy_move, vars);
	mlx_loop(vars->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_mapline		*lines;
	static t_mobs	mobs;
	t_vars			vars;

	parse(ac, av, &lines, &mobs);
	game_init(&vars, &mobs, &lines);
	game(&vars);
	return (exit_game(&vars, EXIT_SUCCESS), 0);
}
