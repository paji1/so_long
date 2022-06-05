/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:47:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/05 12:10:23 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include <math.h>

int spirit(t_vars *vars, int x, int y, t_enemy *enemy)
{
	static int	frame;
	static int	i;
	static int	dir;

	frame++;
	// printf("frame %d\n",y);
	if (!(frame % 1069))
	{
		if (i == 0)
		{
			mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
				vars->imgs.enem1, x*30 , y*30);
			i = 1;
		}
		else
		{
			mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
				vars->imgs.enem2, x*30, y*30);
			i = 0;
		}
	}
	if (frame % 4597 == 0)
	{
		char c = get_mobs(vars, y, x + 1);
		char t = get_mobs(vars, y, x - 1);
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		clear_mobs(vars, x, y);
		if ( rand() % 2 == 0 && (c == '0' || c == 'P') )
				enemy->x += 1;
		if (rand() % 2 == 1 && (t == '0' || t == 'P'))
				enemy->x -= 1;
		put_mobs(vars, enemy->x, enemy->y, 'M');
		if (enemy->x == vars->player.x && enemy->y == vars->player.y)
			exit_game(vars, EXIT_SUCCESS);
		draw_map(vars);
		put_player(vars,vars->keycode);
	}
}


int enemy_move(t_vars *vars)
{
	t_enemy *enemy;
	enemy = vars->enemy;
	while (enemy)
	{
		spirit(vars,enemy->x,enemy->y , enemy);
		enemy = enemy->next;
	}
}

static int game(t_vars *vars)
{
	// mlx_hook(vars->win_ptr , KeyPress,KeyPressMask , keys ,vars);
	vars->enemy = NULL;
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.player.down ,vars->player.x * 30 , \
					vars->player.y * 30);
	mlx_expose_hook(vars->win_ptr, draw_map, vars);
	mlx_hook(vars->win_ptr, KeyPress, KeyPressMask, key_handler, vars);
	mlx_hook(vars->win_ptr, 17,1L, exit_game, vars);
	mlx_loop_hook(vars->mlx_ptr,enemy_move,vars );
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