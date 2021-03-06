/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:15:52 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 09:40:59 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	draw_num(t_vars *vars)
{
	char	*s;

	s = ft_itoa(vars->count);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 15, 15, 0xFFFFFF, s);
	free(s);
}

static void	draw_mobs(t_vars *vars, t_mapline *line, int x, int y)
{
	if (line->line[x] == '1')
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.img_wall, x * 30, vars->window.y - 30 * y);
	else if (line->line[x] == 'C')
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.clocktibe, x * 30, vars->window.y - 30 * y);
	else if (line->line[x] == 'E')
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.door, x * 30, vars->window.y - 30 * y);
	else if (line->line[x] == 'M')
	{
		vars->mobs->enemy += 1;
		if (!vars->start)
			add_mobs(&vars->enemy, new_mobs(x, vars->window.y / \
				30 - y, vars->mobs->enemy - 1));
	}
}

int	draw_map(t_vars *vars)
{
	t_mapline	*line;
	int			x;
	int			y;

	y = 0;
	line = (*vars->lines);
	while (++y <= vars->window.y / 30)
	{
		x = -1;
		while (++x < vars->window.x / 30)
			draw_mobs(vars, line, x, y);
		line = line->next;
	}
	(vars->start)++;
	draw_num(vars);
	return (0);
}
