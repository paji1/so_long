/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 04:43:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 07:46:02 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	is_all_wall(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != '1')
			return (1);
	}
	return (0);
}

int	check_wall(char *line, int i, t_mapline *lines)
{
	if (i == 0 && is_all_wall(line))
		return (1);
	else if (lines->next == NULL && is_all_wall(line))
		return (1);
	else
	{
		if (*line != '1' || line[ft_strlen(line) - 1] != '1')
			return (1);
	}
	return (0);
}
