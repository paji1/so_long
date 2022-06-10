/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 05:35:48 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 08:40:51 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	check_and_destroy(void *img, t_vars *vars, int *check)
{
	if (img)
		mlx_destroy_image(vars->mlx_ptr, img);
	else
		*check = -1;
}

int	exit_game(t_vars *vars, int exit_n)
{
	static int	check;

	check_and_destroy(vars->imgs.img_wall, vars, &check);
	check_and_destroy(vars->imgs.player.up, vars, &check);
	check_and_destroy(vars->imgs.player.down, vars, &check);
	check_and_destroy(vars->imgs.player.left, vars, &check);
	check_and_destroy(vars->imgs.player.right, vars, &check);
	check_and_destroy(vars->imgs.clocktibe, vars, &check);
	check_and_destroy(vars->imgs.door, vars, &check);
	check_and_destroy(vars->imgs.enem1, vars, &check);
	check_and_destroy(vars->imgs.enem2, vars, &check);
	if (check == 0)
		ft_free_mobs(&vars->enemy);
	ft_free(vars->lines);
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free(vars->mlx_ptr);
	if (exit_n == EXIT_FAILURE)
		write(2, "Error\n", 6);
	else if (vars->end == WIN)
		ft_putstr_fd("YOU win\n", 1);
	else if (vars->end == LOSE)
		ft_putstr_fd("YOU lose\n", 1);
	exit(exit_n);
}
