/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:17:39 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/04 11:09:24 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void init_images(t_vars *vars)
{
	vars->imgs.img_wall = mlx_xpm_file_to_image
		(vars->mlx_ptr, "./xpms/wall/wall.xpm",&vars->w,&vars->h);
	vars->imgs.player.up = mlx_xpm_file_to_image
		(vars->mlx_ptr, "./xpms/moves/up.xpm",&vars->w,&vars->h);
	vars->imgs.player.down = mlx_xpm_file_to_image
		(vars->mlx_ptr, "./xpms/moves/down.xpm",&vars->w,&vars->h);
	vars->imgs.player.left = mlx_xpm_file_to_image
		(vars->mlx_ptr, "./xpms/moves/left.xpm",&vars->w,&vars->h);
	vars->imgs.player.right = mlx_xpm_file_to_image
		(vars->mlx_ptr, "./xpms/moves/right.xpm",&vars->w,&vars->h);
	vars->imgs.clocktibe = mlx_xpm_file_to_image
		(vars->mlx_ptr, "./xpms/collect/collect.xpm",&vars->w,&vars->h);
	vars->imgs.door = mlx_xpm_file_to_image
		(vars->mlx_ptr, "./xpms/door/door.xpm",&vars->w,&vars->h);
	if (!vars->imgs.img_wall || !vars->imgs.player.up || \
		!vars->imgs.player.down || !vars->imgs.player.left || \
			!vars->imgs.player.right || !vars->imgs.clocktibe \
				|| !vars->imgs.door)
			exit_game(vars, EXIT_FAILURE);
}

void get_player(t_vars *vars)
{
	int	i;
	int	j;
	t_mapline *line;

	i = 0;
	line = (*vars->lines);
	while (line)
	{
		j = 0;
		while (line->line[j])
		{
			if (line->line[j] == 'P')
			{
				vars->player.x = j;
				vars->player.y = (vars->window.y / 30) - 1 - i;
				clear_mobs(vars, vars->player.x, vars->player.y);
			}
			j++;
		}
		i++;
		line = line->next;
	}
}

void game_init(t_vars *vars, t_mobs *mobs, t_mapline **line)
{
	vars->mobs = mobs;
	vars->lines = line;
	vars->mlx_ptr = mlx_init();
	vars->window.x = (*line)->line_size * 30;
	vars->window.y = rows_size(*line) * 30;
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->window.x,\
		vars->window.y,"so_long");
	get_player(vars);
	init_images(vars);
}