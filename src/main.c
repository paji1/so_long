/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:42 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/31 04:21:40 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_img
{
	void 	*img;
	void	*img_ptr;
	void	*img_ptr2;
	void	*img_ptr3;
	void	*img_ptr4;
}t_img;
typedef struct s_init
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img   imgs;
	void	*temp_img_ptr;
	int x;
	int y;
	int lastkey;
}t_init;



void choose_image(t_init *init,int keycode)
{
	if (keycode == 119)
		init->imgs.img = init->imgs.img_ptr;
	else if (keycode == 97)
		init->imgs.img = init->imgs.img_ptr2;
	else if (keycode == 115)
		init->imgs.img = init->imgs.img_ptr3;
	else if (keycode == 100)
		init->imgs.img = init->imgs.img_ptr4;
	init->lastkey = keycode;
	if (keycode == 0xff1b)
		exit(EXIT_SUCCESS);
}

int fun(int keycode,void *param)
{
	t_init *init = (t_init *)param;
	
	if (keycode == 119)
		init->y -=60;
	else if (keycode == 97)
		init->x -= 60;
	else if (keycode == 115)
		init->y += 60;
	else if (keycode == 100)
		init->x += 60;
	if (keycode == 0xff1b)
		exit(EXIT_SUCCESS);
	printf("%d\n",keycode);
	choose_image(init , keycode);
	mlx_clear_window ( init->mlx_ptr, init->win_ptr );
	mlx_put_image_to_window(init->mlx_ptr, init->win_ptr,init->imgs.img,init->x,init->y );
	return 0;

}
int funn(char *param)
{
	

	printf("hello\n");
	return 0;
}
int	main(void)
{
	t_init init;
	void *win_ptr2;

	int x,y;
	init.y = 0;
	init.x = 0;
	init.lastkey = 0;
	init.mlx_ptr = mlx_init();
	init.win_ptr = mlx_new_window(init.mlx_ptr, 500, 500, "Hello world!");
	init.imgs.img_ptr = mlx_xpm_file_to_image(init.mlx_ptr , "./xpms/attack/01.xpm",&x,&y);
	init.imgs.img = init.imgs.img_ptr;
	init.imgs.img_ptr2 = mlx_xpm_file_to_image(init.mlx_ptr , "./xpms/attack/02.xpm",&x,&y);
	init.imgs.img_ptr3 = mlx_xpm_file_to_image(init.mlx_ptr , "./xpms/attack/03.xpm",&x,&y);
	init.imgs.img_ptr4 = mlx_xpm_file_to_image(init.mlx_ptr , "./xpms/attack/04.xpm",&x,&y);

	mlx_put_image_to_window(init.mlx_ptr, init.win_ptr, init.imgs.img_ptr,init.x,init.y);
 	mlx_key_hook  (init.win_ptr, fun, &init);
	// mlx_loop_hook(init.mlx_ptr,funn, "hello");
	mlx_expose_hook(init.win_ptr , funn,&init);
	mlx_hook(init.win_ptr,KeyPress,KeyPressMask,funn, 0);
	// mlx_hook(init.win_ptr, 3, 1L<<1,funn,&init);
	// mlx_do_key_autorepeaton(init.mlx_ptr);
	// mlx_put_image_to_window(init.mlx_ptr, init.win_ptr, init.img_ptr,init.x,init.y);
	// mlx_get_data_addr (img_ptr,&img.bits_per_pixel, &img.size_line, &img.endien);
	// mlx_get_color_value(mlx_ptr, 0xFFFFFF);
	mlx_loop(init.mlx_ptr);
}