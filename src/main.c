/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:42 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/05 00:57:10 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	put_player(t_vars * vars, int keycode)
{
	if (keycode == XK_s)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.player.down ,vars->player.x * 30 , \
					vars->player.y*30);
	else if (keycode == XK_w)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.player.up ,vars->player.x * 30 , \
					vars->player.y*30);
	else if (keycode == XK_a)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.player.left ,vars->player.x * 30 , \
					vars->player.y*30);
	else if (keycode == XK_d)
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.player.right ,vars->player.x * 30 , \
					vars->player.y*30);
}

void print_moves(int *num)
{
	ft_putstr_fd("NUmers of moves = ", 1);
	ft_putnbr_fd(++(*num) , 1);
	ft_putchar_fd('\n', 1);
}
void check_sq(t_vars *vars, int keycode, char mobs)
{
	int static n_moves;
	
	if (mobs == '0'  || mobs == 'C')
	{
		if (keycode == XK_s)
			vars->player.y += 1;
		else if (keycode == XK_w)
			vars->player.y -= 1;
		else if (keycode == XK_a)
			vars->player.x -= 1;
		else if (keycode == XK_d)
			vars->player.x += 1;
		if (mobs == 'C')
		{
			vars->mobs->collectible -= 1;
			clear_mobs(vars, vars->player.x, vars->player.y);
		}
		print_moves(&n_moves);
	}
	else if (mobs == 'E' && !vars->mobs->collectible)
		exit_game(vars, EXIT_SUCCESS);
	mlx_clear_window(vars->mlx_ptr , vars->win_ptr);
	draw_map(vars);
	put_player(vars,keycode);
}

void player_key_handler(int key, t_vars *vars)
{
	if (key == XK_w)
		check_sq(vars, key, get_mobs(vars, vars->player.y - 1, vars->player.x));
	else if (key == XK_s)
		check_sq(vars, key, get_mobs(vars, vars->player.y + 1, vars->player.x));
	else if (key == XK_d)
		check_sq(vars, key, get_mobs(vars, vars->player.y, vars->player.x + 1));
	else if (key == XK_a)
		check_sq(vars, key, get_mobs(vars, vars->player.y, vars->player.x - 1));

}
int key_handler(int keycode , t_vars *vars)
{
	if (keycode == XK_Escape || keycode == XK_q)
		exit_game(vars, EXIT_SUCCESS);
	else if (keycode == XK_w || keycode == XK_a || keycode == XK_s\
		 || keycode == XK_d)
		player_key_handler(keycode, vars);
}
int game(t_vars *vars)
{
	// mlx_hook(vars->win_ptr , KeyPress,KeyPressMask , keys ,vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.player.down ,vars->player.x * 30 , \
					vars->player.y*30);
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
