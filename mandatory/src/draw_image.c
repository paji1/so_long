/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:15:52 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 10:37:17 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void clear_mobs(t_vars *vars, int x, int y)
{
	int	i;
	int	j;
	t_mapline *line;

	i = 0;
	j = 0;
	line = (*vars->lines);
	while (line)
	{
		if (vars->window.y / 30 - i -1 == y)
			line->line[x] = '0';
		i++;
		line = line->next;
	}
}

static void	draw_mobs(t_vars *vars, t_mapline *line, int x, int y)
{
	if (line->line[x] == '1')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.img_wall,x *30, vars->window.y - 30 * y);
	else if (line->line[x] == 'C')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.clocktibe,x *30, vars->window.y - 30 * y);
	else if (line->line[x] == 'E')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr, \
				vars->imgs.door,x *30, vars->window.y - 30 * y);
	else if (line->line[x] == 'M')
		clear_mobs(vars, x , vars->window.y / 30  - y);
}

int draw_map(t_vars *vars)
{
	t_mapline	*line;
	int			x;
	int 		y;

	y = 0;
	line = (*vars->lines);
	while (++y <= vars->window.y / 30)
	{
		x = -1;
		while (++x < vars->window.x / 30)
			draw_mobs(vars, line, x, y);
		line = line->next;
	}
	return (0);
}