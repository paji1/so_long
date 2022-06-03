/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:42 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/03 05:58:39 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


typedef struct s_player_img
{
	void *up;
	void *down;
	void *left;
	void *right;
	void *stand;
}t_player_img;

typedef struct s_imgs
{
	void			*img_wall;
	t_player_img	player;
	void			*floor;
	void			*clocktibe;
}t_img;

typedef struct s_win_size
{
	int x;
	int y;
}t_wsize;
typedef struct s_player_size
{
	int x;
	int y;
}t_psize;


typedef struct s_vars
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		imgs;
	t_mobs		*mobs;
	int			x;
	int			y;
	t_wsize		window;
	t_psize		player;
	t_mapline	*lines;
}t_vars;

void game_init(t_vars *vars, t_mobs *mobs, t_mapline *line)
{
	vars->mobs = mobs;
	vars->mlx_ptr = mlx_init();
	vars->window.x = line->line_size * 32;
	vars->window.y = rows_size(line) * 32;
	vars->win_ptr = mlx_new_window(vars->mlx_ptr,vars->window.x,\
		vars->window.y,"so_long");
	printf("window %d" , vars->window.y);
}


int main(int ac, char  **av)
{
	t_mapline		*lines;
	static t_mobs	mobs;
	t_vars			vars;

	parse(ac, av, &lines, &mobs);
	game_init(&vars, &mobs, lines);

	mlx_loop(vars.mlx_ptr);
	return ft_free(&lines),0;
}