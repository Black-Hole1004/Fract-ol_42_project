/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:02:02 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/25 20:40:26 by ahmaymou         ###   ########.fr       */
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
        color.b = (unsigned char)(50 - (i * 2.55)); // color.b = 0; is amazing;
        color.g = (unsigned char)(i * 6);
		c += (color.r << 16) + (color.g << 8) + color.b;
    }
    return c;
}

int mouse_move(int x_pos, int y_pos, t_mlx_info *info)
{
	// info->fix = CMPLX(x_pos, y_pos);
	// mlx_mouse_get_pos(info->window_ptr, &x_pos, &y_pos);
	info->fix = convert(x_pos, y_pos, info);
	draw("mandelbrot", info);
	return (0);
}

int mouse_scroll(int button, int x_pos, int y_pos, t_mlx_info *info)
{
	(void)x_pos;
	(void)y_pos;
	mlx_clear_window(info->mlx_ptr, info->window_ptr);
	// mlx_destroy_image(info->mlx_ptr, info->img);
    if (button == 5)
	{
        info->zoom /= 1.1;
		info->mouse_x = x_pos;
		info->mouse_y = y_pos;
	}
    else if (button == 4)
	{
        info->zoom *= 1.1;
		info->mouse_x = x_pos;
		info->mouse_y = y_pos;
	}
	draw("mandelbrot", info);
	return (info->zoom);
}

int	cross_destroy(void)
{
	exit(0);
}

int	destroy(t_mlx_info *info)
{
	// mlx_destroy_image(info->mlx_ptr, info->img);
	mlx_destroy_window(info->mlx_ptr, info->window_ptr);
	exit(0);
}

int	change_pal(int key, t_mlx_info *info)
{
    if (key == 123)
		info->p += 1;
    else if (key == 124)
		info->p -= 1;
	if (info->p == 4)
		info->p = 0;
	else if (info->p == -1)
		info->p = 3;
    else if (key == 13)   // keycode for 'w'
        info->ymax += 0.5;
    else if (key == 0)    // keycode for 'a'
       info->xmax += 0.5;
	else if (key == 1)
		info->ymax -= 0.5; // keycode for 's'
	else if (key == 2)
		info->xmax -= 0.5; // keycode for 'd'
	else if (key == 53)
		destroy(info);
	draw("mandelbrot", info);
	return (0);
}

void	my_mlx_pixel_put(t_mlx_info *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	// t_data  img;
	t_mlx_info	info;
	// int x, y;
	init(&info);
	// info.line_length /= 4;
	draw("mandelbrot", &info);
	// draw_odd("mandelbrot", &info);
	// mlx_key_hook(info.window_ptr, destroy, &info);
	mlx_key_hook(info.window_ptr, change_pal, &info);
	// mlx_mouse_get_pos(info.window_ptr, &x, &y);
	// printf("x :%d y: %d\n", x, y);
	mlx_hook(info.window_ptr, 6, 0, mouse_move, &info);
	mlx_hook(info.window_ptr, 4, 0, mouse_scroll, &info);
	mlx_hook(info.window_ptr, 17, 0, cross_destroy, &info);
	mlx_loop(info.mlx_ptr);
	system("leaks fractol");
	// for (int i = 0;i<4;i++)
	// 	free(palettes[i]);
	// free(palettes);
	// mlx_destroy_window(info.mlx_ptr, info.window_ptr);
	return (0);
}