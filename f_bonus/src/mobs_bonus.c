/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobs_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:37:47 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 08:54:55 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	clear_mobs(t_vars *vars, int x, int y)
{
	int			i;
	int			j;
	t_mapline	*line;

	i = 0;
	j = 0;
	line = (*vars->lines);
	while (line)
	{
		if (vars->window.y / 30 - i - 1 == y)
			line->line[x] = '0';
		i++;
		line = line->next;
	}
}

void	put_mobs(t_vars *vars, int x, int y, char mobs)
{
	int			i;
	int			j;
	t_mapline	*line;

	i = 0;
	j = 0;
	line = (*vars->lines);
	while (line)
	{
		if (vars->window.y / 30 - i - 1 == y)
			line->line[x] = mobs;
		i++;
		line = line->next;
	}
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
		if (vars->window.y / 30 - i - 1 == y)
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
