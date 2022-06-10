/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 06:23:52 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 11:56:39 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_mobs
{
	int	players;
	int	wall;
	int	empty;
	int	exit;
	int	collectible;
	int	enemy;
}t_mobs;

typedef struct s_mapline
{
	char				*line;
	int					line_size;
	struct s_mapline	*next;
}t_mapline;

typedef struct s_player_img
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
}t_player_img;

typedef struct s_imgs
{
	void			*img_wall;
	t_player_img	player;
	void			*door;
	void			*clocktibe;
	void			*enem1;
	void			*enem2;
}t_img;

typedef struct s_win_size
{
	int	x;
	int	y;
}t_wsize;

typedef struct s_player_size
{
	int	x;
	int	y;
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