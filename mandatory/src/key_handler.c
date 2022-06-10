/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 05:43:21 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 11:38:18 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	print_moves(int *num)
{
	ft_putstr_fd("NUmers of moves = ", 1);
	ft_putnbr_fd(++(*num), 1);
	ft_putchar_fd('\n', 1);
}

static void	key_op(t_vars *vars, int keycode)
{
	if (keycode == XK_S)
		vars->player.y += 1;
	else if (keycode == XK_W)
		vars->player.y -= 1;
	else if (keycode == XK_A)
		vars->player.x -= 1;
	else if (keycode == XK_D)
		vars->player.x += 1;
}

static void	check_sq(t_vars *vars, int keycode, char mobs)
{
	static int	n_moves;

	if (mobs == '0' || mobs == 'C')
	{
		key_op(vars, keycode);
		if (mobs == 'C')
		{
			vars->mobs->collectible -= 1;
			clear_mobs(vars, vars->player.x, vars->player.y);
		}
		print_moves(&n_moves);
	}
	else if (mobs == 'E' && !vars->mobs->collectible)
	{
		print_moves(&n_moves);
		ft_putstr_fd("\nyou win\n", 1);
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
