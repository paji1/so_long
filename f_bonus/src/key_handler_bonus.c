/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 05:43:21 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 11:38:18 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	put_player(t_vars *vars, int keycode)
{
	if (keycode == XK_W)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.player.up, vars->player.x * 30, \
					vars->player.y * 30);
	else if (keycode == XK_A)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.player.left, vars->player.x * 30, \
					vars->player.y * 30);
	else if (keycode == XK_D)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.player.right, vars->player.x * 30, \
					vars->player.y * 30);
	else
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.player.down, vars->player.x * 30, \
					vars->player.y * 30);
}

static void	handle_collectible(t_vars *vars, int keycode, char mobs)
{
	clear_mobs(vars, vars->player.x, vars->player.y);
	if (keycode == XK_S)
		vars->player.y += 1;
	else if (keycode == XK_W)
		vars->player.y -= 1;
	else if (keycode == XK_A)
		vars->player.x -= 1;
	else if (keycode == XK_D)
		vars->player.x += 1;
	if (mobs == 'C')
	{
		vars->mobs->collectible -= 1;
		clear_mobs(vars, vars->player.x, vars->player.y);
	}
	vars->count += 1;
	put_mobs(vars, vars->player.x, vars->player.y, 'P');
}

static void	check_sq(t_vars *vars, int keycode, char mobs)
{
	vars->keycode = keycode;
	if (mobs == '0' || mobs == 'C')
		handle_collectible(vars, keycode, mobs);
	else if (mobs == 'E' && !vars->mobs->collectible)
	{
		vars->end = WIN;
		exit_game(vars, EXIT_SUCCESS);
	}
	else if (mobs == 'M')
	{
		vars->end = LOSE;
		exit_game(vars, EXIT_SUCCESS);
	}
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	draw_map(vars);
	put_player(vars, keycode);
}

static void	player_key_handler(int key, t_vars *vars)
{
	if (key == XK_W)
		check_sq(vars, key, get_mobs(vars, vars->player.y - 1, vars->player.x));
	else if (key == XK_S)
		check_sq(vars, key, get_mobs(vars, vars->player.y + 1, vars->player.x));
	else if (key == XK_D)
		check_sq(vars, key, get_mobs(vars, vars->player.y, vars->player.x + 1));
	else if (key == XK_A)
		check_sq(vars, key, get_mobs(vars, vars->player.y, vars->player.x - 1));
}

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == XK_ESCAPE || keycode == XK_Q)
		exit_game(vars, EXIT_SUCCESS);
	else if (keycode == XK_W || keycode == XK_A || keycode == XK_S \
		|| keycode == XK_D)
		player_key_handler(keycode, vars);
	return (0);
}
