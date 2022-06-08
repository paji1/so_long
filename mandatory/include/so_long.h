/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 06:23:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/08 09:25:22 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG


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

#include "types.h"

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
int			key_handler(int keycode , t_vars *vars);

#endif