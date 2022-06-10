/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:28:31 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 09:43:27 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	check_mobs(t_mapline *line, t_mobs *mobs)
{
	int	i;

	i = -1;
	while ((line->line)[++i])
	{
		if (line->line[i] == PLAYER)
			mobs->players += 1;
		else if (line->line[i] == EXIT)
			mobs->exit += 1;
		else if (line->line[i] == COLLECTIBLE)
			mobs->collectible += 1;
	}
	if ((!mobs->collectible || !mobs->exit || mobs->players != 1) && \
		!line->next)
		return (1);
	return (0);
}

static int	check_valid(t_mapline **lines, t_mobs *mobs)
{
	int			i;
	t_mapline	*line;

	line = *lines;
	i = 0;
	while (line)
	{
		if (check_wall(line->line, i, line))
			return (write(2, "Error\n", 6), ft_free(lines), 1);
		if (check_mobs(line, mobs))
			return (write(2, "Error\n", 6), ft_free(lines), 1);
		i++;
		line = line->next;
	}
	return (0);
}

int	parse(int ac, char **av, t_mapline **lines, t_mobs *mobs)
{
	int	fd;

	if (ac != 2)
		return (write(2, "Error\n", 6), exit(EXIT_FAILURE), 1);
	fd = open(av[1], O_RDWR);
	(*lines) = NULL;
	if (check_ber(av[1]) || fd < 0)
		return (write(2, "Error\n", 6), exit(EXIT_FAILURE), 1);
	while (str_to_lines(get_next_line(fd), lines))
		;
	if (check_valid(lines, mobs))
		exit(EXIT_FAILURE);
	return (0);
}
