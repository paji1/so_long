/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:51:19 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/01 03:13:07 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

t_mapline *newline(char *s)
{
	t_mapline *newline;

	newline = malloc(sizeof(t_mapline));
	newline->line = ft_strdup(s);
	return newline;
}

void add_line(t_mapline **lines, t_mapline *newline)
{
	newline->next = *lines;
	*lines = newline;
}
