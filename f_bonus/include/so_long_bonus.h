/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 06:23:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/08 09:25:59 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

#include <mlx.h>
#include <stdlib.h>

#ifdef LINUX
#include "../../minilibx/mlx.h"
#include <X11/XKBlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#endif

#ifdef MAC
#include "../../minilibx-linux/mlx.h"
#include "key_handler.h"
#endif

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/include/libft.h"
#include "../gnl/get_next_line.h"

#include "types_bonus.h"
# define LOSE 3
# define WIN 2
# define NOTHING 1
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'

t_mapline	*newline(char *s);
void		add_line(t_mapline **lines, t_mapline *newline);
int			check_ber(char *s);
int			check_len(char *s, int len, t_mapline **lines);
int			str_to_lines(char *s, t_mapline **lines);
int			parse(int ac, char **av, t_mapline **lines, t_mobs *mobs);
void		ft_free(t_mapline **lst);
int			check_wall(char *line, int i, t_mapline *lines);
int 		rows_size(t_mapline *lines);
int			draw_map(t_vars *vars);
void		game_init(t_vars *vars, t_mobs *mobs, t_mapline **line);
void		init_images(t_vars *vars);
int			exit_game(t_vars *vars,int exit_n);
char		get_mobs(t_vars *vars, int y, int x);
void		clear_mobs(t_vars *vars, int x, int y);
void		put_player(t_vars * vars, int keycode);
int			key_handler(int keycode , t_vars *vars);
void		add_mobs(t_enemy **lines, t_enemy *newline);
t_enemy		*new_mobs(int x, int y, int id);
void		put_mobs(t_vars *vars, int x, int y, char mobs);
void		ft_free_mobs(t_enemy **lst);
int			enemy_move(t_vars *vars);
#endif
