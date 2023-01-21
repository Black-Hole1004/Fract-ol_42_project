/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:02:02 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/21 20:51:15 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// unsigned int get_color(int i){
//     if (i == 100) {
//         return 0; // black color
//     }
//     return (unsigned char)(i * 2.55);
// }

unsigned int get_color(int i) {
    struct RGB color;
	unsigned int c  = 0;
    if (i == MAX_ITER) {
        c = 0;
    } else {
        color.r = (unsigned char)(i * 2.55);
        color.b = (unsigned char)(100 - (i * 2.55));// color.b = 0; is amazing;
        color.g = (unsigned char)(i * 5);
		c += (color.r << 16) + (color.g << 8) + color.b;
    }
    return c;
}

int mouse_move(int x_pos, int y_pos, t_mlx_info *info)
{
	info->mouse_x = x_pos;
	info->mouse_y = y_pos;
	// printf("x :%d y :%d\n", x, y);
	return (0);
}

int mouse_scroll(int button, int x_pos, int y_pos, t_mlx_info *info)
{
	(void)x_pos, (void)y_pos;

	ft_printf("%p %p\n", info->mlx_ptr, info->window_ptr);
    if (button == 5)
	{
        info->zoom /= 1.2;
		info->mouse_x = x_pos;
		info->mouse_y = y_pos;
	}
    else if (button == 4)
	{
        info->zoom *= 1.2;
		info->mouse_x = x_pos;
		info->mouse_y = y_pos;
	}
	draw(info->mlx_ptr, info->window_ptr, "mandelbrot", info);
	return (info->zoom);
}

int	change_pal(int key, t_mlx_info *info)
{
    if (key == 123)
		info->p += 1;
    else if (key == 124)
		info->p -= 1;
    else if (key == 0x0057) // keycode for 'w'
        printf("suii\n");
    else if (key == 0x0053) // keycode for 's'
        puts("hehe\n");
	// info->p = info->p % 4;
	if (info->p == 3)
		info->p = 0;
	else if (info->p == -1)
		info->p = 3;
	draw(info->mlx_ptr, info->window_ptr, "mandelbrot", info);
    // } else if (key == 126) { // up arrow
    //     printf("Up arrow pressed\n");
    //     // do something
    // } else if (key == 125) { // down arrow
    //     printf("Down arrow pressed\n");
    //     // do something
    // }
	return (0);
}
// int main()
// {
//     void *mlx_ptr;
//     void *mlx_win;

//     mlx_ptr = mlx_init();
//     mlx_win = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Example Window");

//     mlx_hook(mlx_win, 6, 0, mouse_move, 0);
//     printf("%d\n",mlx_hook(mlx_win, 4, 0, mouse_scroll, 0));
//     mlx_loop(mlx_ptr);

//     return 0;
// }

// int	**pal_init(int **palettes)
// {

// 	return (palettes);
// }
int	main(void)
{
	// void	*mlx_ptr;
	// void	*window_ptr;
	t_mlx_info	info;

	// int palette[11] = {BLACK,
	// RED,
	// ORANGERED1,
	// ORANGERED2,
	// ORANGERED3,
	// ORANGERED4,
	// DARKORANGE,
	// ORANGE1,
	// ORANGE2,
	// ORANGE3,};
	// int palette1[11] = ;
	// int palette2[11] = ;
	// int palette3[11] = ;
	int **palettes = malloc(4 * sizeof(int*));
	int palette4[] = {C41, BLACK, C43, C44, C45, C46, C47, C48,C49,C410,C411};
	int palette1[] = {C11, BLACK, C13, C14, C15, C16, C17, C18,C19,C110,C111};
	int palette2[] = {C21, BLACK, C23, C24, C25, C26, C27, C28,C29,C210,C211};
	int palette3[] = {C31, BLACK, C33, C34, C35, C36, C37, C38,C39,C310,C311};
	palettes[0] = palette1;
	palettes[1] = palette2;
	palettes[2] = palette3;
	palettes[3] = palette4;
	// int red;
	// int blue;
	// int green;
	// int color = 0;
	// palettes = pal_init(palettes);
	init(&info, palettes);
	// ft_printf("suiii\n");
	// draw_odd(info.mlx_ptr, info.window_ptr, "mandelbrot", &info);
	draw(info.mlx_ptr, info.window_ptr, "mandelbrot", &info);
	mlx_key_hook(info.window_ptr, change_pal, &info);
	// mlx_hook(info.window_ptr, 6, 0, mouse_move, &info);
	mlx_hook(info.window_ptr, 4, 0, mouse_scroll, &info);
	// // if (zoom != DEFAULT_ZOOM)
	// 	printf("yes\n");
	mlx_loop(info.mlx_ptr);
	// mlx_destroy_window(mlx_ptr, window_ptr);
	return (0);
}