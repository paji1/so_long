/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:28:31 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/01 03:27:14 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"






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
}