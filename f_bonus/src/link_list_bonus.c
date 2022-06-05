/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:51:19 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/05 10:38:04 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long_bonus.h"

t_mapline	*newline(char *s)
{
	t_mapline *newline;

	newline = malloc(sizeof(t_mapline));
	newline->line = ft_strdup(s);
	return (newline);
}

t_enemy	*new_mobs(int x, int y, int id)
{
	t_enemy *newline;
	newline = malloc(sizeof(t_enemy));
	newline->x = x;
	newline->y = y;
	newline->id = id;
	
	return (newline);
}

void	add_mobs(t_enemy **lines, t_enemy *newline)
{
	newline->next = *lines;
	*lines = newline;
}

void	add_line(t_mapline **lines, t_mapline *newline)
{
	newline->next = *lines;
	*lines = newline;
}

int	rows_size(t_mapline *lines)
{
	int	i;

	i = 0;
	while (lines)
	{
		i++;
		lines = lines->next;
	}
	return (i);
}

