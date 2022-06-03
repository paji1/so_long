/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 06:23:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/03 06:23:57 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

#include <mlx.h>
#include <stdlib.h>
#include <X11/XKBlib.h>
#include <X11/X.h>
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
#endif