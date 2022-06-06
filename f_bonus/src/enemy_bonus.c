/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 07:39:35 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/06 12:21:24 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"


static void rand_move(t_vars *vars, int x, int y, t_enemy *enemy)
{
	char c;
	char t;

	c = get_mobs(vars, y, x + 1);
	t = get_mobs(vars, y, x - 1);
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	clear_mobs(vars, x, y);
	if (rand() % 2 == 0 && (c == '0' || c == 'P') )
			enemy->x += 1;
	else if (rand() % 2 == 1 && (t == '0' || t == 'P'))
			enemy->x -= 1;
	put_mobs(vars, enemy->x, enemy->y, 'M');
	if (enemy->x == vars->player.x && enemy->y == vars->player.y)
	{
		vars->end = LOSE;
		exit_game(vars, EXIT_SUCCESS);
	}
	draw_map(vars);
	put_player(vars,vars->keycode);
}

static int spirit(t_vars *vars, int x, int y, t_enemy *enemy)
{
	static int	frame;
	static int	i;

	if (!(++frame % 1069))
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
	else if (frame % 4597 == 0)
		rand_move(vars, x, y, enemy);
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