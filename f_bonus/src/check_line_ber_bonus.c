/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_ber_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:53:14 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 09:52:40 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	check_ber(char *s)
{
	int	len;

	len = ft_strlen(s);
	while (--len >= 0)
	{
		if (s[len] == '.')
		{
			if (!ft_strcmp(s + len, ".ber"))
				return (0);
			else
				return (1);
		}
	}
	return (1);
}

static void	exit_and_free(t_mapline **lines, char *s)
{
	ft_free(lines);
	free(s);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	check_len(char *s, int len, t_mapline **lines)
{
	int	i;

	i = ft_strlen(s);
	if (s[i] == '\0' && s[i - 1] != '\n' && i != len)
		exit_and_free(lines, s);
	else if (s[i - 1] == '\n' && i != len + 1)
		exit_and_free(lines, s);
	s[len] = 0;
}

int	str_to_lines(char *s, t_mapline **lines)
{
	static int	len;

	if (!len)
	{
		if (!s)
		{
			write(2, "Empty\n", 6);
			exit(EXIT_FAILURE);
		}
		len = ft_strlen(s) - 1;
	}
	if (s && *s != '\n' && *s)
	{
		check_len(s, len, lines);
		return (add_line(lines, newline(s)), (*lines)->line_size = len, \
			free(s), 1);
	}
	else
		return (free(s), 0);
}
