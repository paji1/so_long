/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:42 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/03 07:45:10 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void game_init(t_vars *vars, t_mobs *mobs, t_mapline **line)
{
	int w,h;
	vars->mobs = mobs;
	vars->lines = line;
	vars->mlx_ptr = mlx_init();
	vars->window.x = (*line)->line_size * 30;
	vars->window.y = rows_size(*line) * 30;
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->window.x,\
		vars->window.y,"so_long");
	vars->imgs.player.stand = mlx_xpm_file_to_image(vars->mlx_ptr, "./xpms/attack/01.xpm",&vars->w,&vars->h);
	// vars->imgs.player.stand = mlx_xpm_file_to_image(vars->mlx_ptr, "./xpms/attack/02.xpm",&vars->w,&vars->h);
}



// int draw_map(t_var *vars)
// {
	
// }
// int game(t_vars *vars)
// {
	
// }


int main(int ac, char  **av)
{
	t_mapline		*lines;
	static t_mobs	mobs;
	t_vars			vars;

	parse(ac, av, &lines, &mobs);
	game_init(&vars, &mobs, &lines);

	mlx_loop(vars.mlx_ptr);
	return ft_free(&lines),0;
}