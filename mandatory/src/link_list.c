/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:51:19 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 11:32:16 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_mapline	*newline(char *s)
{
	t_mapline	*newline;

	newline = malloc(sizeof(t_mapline));
	newline->line = ft_strdup(s);
	return (newline);
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

char	get_mobs(t_vars *vars, int y, int x)
{
	int			i;
	int			j;
	t_mapline	*line;

	i = 0;
	j = 0;
	line = (*vars->lines);
	while (line)
	{
		if (vars->window.y / 30 - i -1 == y)
		{
			while (line->line[j])
			{
				if (j == x)
					return (line->line[j]);
				j++;
			}
		}
		i++;
		line = line->next;
	}
	return (-1);
}
