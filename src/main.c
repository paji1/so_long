/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:42 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/01 03:35:41 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int main(int ac, char  **av)
{
	t_mapline *lines;
	
	parse(ac, av, &lines);
	return ft_free(&lines),0;
}