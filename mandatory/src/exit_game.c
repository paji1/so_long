/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 05:35:48 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/05 06:42:08 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



int exit_game(t_vars *vars,int exit_n)
{
		if (vars->imgs.player.down)
			mlx_destroy_image(vars->mlx_ptr,vars->imgs.player.down);
		if (vars->imgs.img_wall)
			mlx_destroy_image(vars->mlx_ptr,vars->imgs.img_wall);
		if (vars->imgs.player.up)
			mlx_destroy_image(vars->mlx_ptr,vars->imgs.player.up);
		if (vars->imgs.player.left)
			mlx_destroy_image(vars->mlx_ptr,vars->imgs.player.left);
		if (vars->imgs.player.right)
			mlx_destroy_image(vars->mlx_ptr,vars->imgs.player.right);
		if (vars->imgs.clocktibe)
			mlx_destroy_image(vars->mlx_ptr,vars->imgs.clocktibe);
		if (vars->imgs.door)
			mlx_destroy_image(vars->mlx_ptr,vars->imgs.door);
		ft_free(vars->lines);
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
		if (exit_n == EXIT_FAILURE)
			write(2, "Error\n", 6);
		exit(exit_n);
}