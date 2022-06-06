/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 05:35:48 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/06 11:14:27 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void check_and_destroy(void *img, t_vars *vars)
{
	if (img)
		mlx_destroy_image(vars->mlx_ptr,img);
}

int exit_game(t_vars *vars,int exit_n)
{
	check_and_destroy(vars->imgs.player.down, vars);
	check_and_destroy(vars->imgs.img_wall, vars);
	check_and_destroy(vars->imgs.player.up, vars);
	check_and_destroy(vars->imgs.player.left, vars);
	check_and_destroy(vars->imgs.player.right, vars);
	check_and_destroy(vars->imgs.clocktibe, vars);
	check_and_destroy(vars->imgs.door, vars);
	check_and_destroy(vars->imgs.enem1, vars);
	check_and_destroy(vars->imgs.enem2, vars);
	ft_free_mobs(&vars->enemy);
	ft_free(vars->lines);
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	if (exit_n == EXIT_FAILURE)
		write(2, "Error\n", 6);
	else if (vars->end == WIN)
		ft_putstr_fd("YOU win\n", 1);
	else if (vars->end == LOSE)
		ft_putstr_fd("YOU lose\n", 1);
	exit(exit_n);		
}