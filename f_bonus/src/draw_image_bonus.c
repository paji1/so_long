/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:15:52 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/05 12:18:25 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void draw_num(t_vars *vars)
{
	char *s = ft_itoa(vars->count);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr ,15,15,0xFF0000,s);
	free(s);
}

int draw_map(t_vars *vars)
{
	t_mapline	*line;
	int			x;
	int 		y;
	static int 	start;

	y = 0;
	line = (*vars->lines);
	while (++y <= vars->window.y / 30)
	{
		x = -1;
		while (++x < vars->window.x / 30)
		{
			if (line->line[x] == '1')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
						vars->imgs.img_wall,x *30, vars->window.y - 30 * y);
			else if (line->line[x] == 'C')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
						vars->imgs.clocktibe,x *30, vars->window.y - 30 * y);
			else if (line->line[x] == 'E')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
						vars->imgs.door,x *30, vars->window.y - 30 * y);
			else if (line->line[x] == 'M')
			{
				vars->mobs->enemy += 1;
				if (!start)
					add_mobs(&vars->enemy, new_mobs(x , vars->window.y /\
					 30  - y , vars->mobs->enemy - 1));
			}
		}
		line = line->next;
	}
	start++;
	draw_num(vars);
}
