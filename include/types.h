/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 06:23:52 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/03 07:37:37 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_mobs
{
	int players;
	int wall;
	int empty;
	int exit;
	int collectible;
}t_mobs;

typedef struct s_mapline
{
	char				*line;
	int					line_size;
	struct s_mapline	*next;
}t_mapline;

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
	int			w;
	int			h;
	int			x;
	int			y;
	t_wsize		window;
	t_psize		player;
	t_mapline	**lines;
}t_vars;

#endif