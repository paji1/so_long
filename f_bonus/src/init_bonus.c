/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:17:39 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 08:46:50 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	handle_img(t_vars *vars, char *str, void **img)
{
	int	fd;

	*img = NULL;
	*img = mlx_xpm_file_to_image
		(vars->mlx_ptr, str, &vars->w, &vars->h);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit_game(vars, EXIT_FAILURE);
	else
		close(fd);
}

static void	init_with_null(t_vars *vars)
{
	vars->imgs.img_wall = NULL;
	vars->imgs.player.up = NULL;
	vars->imgs.player.left = NULL;
	vars->imgs.player.down = NULL;
	vars->imgs.player.right = NULL;
	vars->imgs.clocktibe = NULL;
	vars->imgs.door = NULL;
	vars->imgs.enem1 = NULL;
	vars->imgs.enem2 = NULL;
}

void	init_images(t_vars *vars)
{	
	init_with_null(vars);
	handle_img(vars, "./f_bonus/xpms/wall/wall.xpm", &vars->imgs.img_wall);
	handle_img(vars, "./f_bonus/xpms/moves/up.xpm", &vars->imgs.player.up);
	handle_img(vars, "./f_bonus/xpms/moves/down.xpm", &vars->imgs.player.down);
	handle_img(vars, "./f_bonus/xpms/moves/left.xpm", &vars->imgs.player.left);
	handle_img(vars, "./f_bonus/xpms/moves/right.xpm", \
		&vars->imgs.player.right);
	handle_img(vars, "./f_bonus/xpms/collect/collect.xpm", \
		&vars->imgs.clocktibe);
	handle_img(vars, "./f_bonus/xpms/door/door.xpm", &vars->imgs.door);
	handle_img(vars, "./f_bonus/xpms/enemy/enem1.xpm", &vars->imgs.enem1);
	handle_img(vars, "./f_bonus/xpms/enemy/enem2.xpm", &vars->imgs.enem2);
}

void	get_player(t_vars *vars)
{
	int			i;
	int			j;
	t_mapline	*line;

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

void	game_init(t_vars *vars, t_mobs *mobs, t_mapline **line)
{
	vars->mobs = mobs;
	vars->lines = line;
	vars->count = 0;
	vars->start = 0;
	vars->mlx_ptr = mlx_init();
	vars->window.x = (*line)->line_size * 30;
	vars->window.y = rows_size(*line) * 30;
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->window.x, \
		vars->window.y, "so_long");
	get_player(vars);
	init_images(vars);
}
