/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:28:31 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/01 05:02:26 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"




// typedef struct s_valid_p
// {
// 	int players;
// 	int wall;
// 	int empty;
// 	int exit;
// 	int collectible;
// }t_valid_p;


static int check_valid(t_mapline **lines)
{
	int i;
	t_mapline *line;

	i = 0;
	line = *lines;
	while (line)
	{
		if (check_wall(line->line, i,line))
			return write(2, "ERROR\n",6),ft_free(lines),1;
		
		i++;	
		line = line->next;
	}
}
int parse(int ac, char **av, t_mapline **lines)
{
	int	fd;

	if (ac != 2)
		return 1;
	fd = open(av[1], O_RDWR);
	(*lines) = NULL;
	if (check_ber(av[1]) || fd < 0)
		return 1;
	while (str_to_lines(get_next_line(fd), lines))
		;
	if (check_valid(lines))
		exit(EXIT_FAILURE);
}