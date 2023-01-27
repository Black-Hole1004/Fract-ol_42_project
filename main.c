/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:02:02 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/27 23:16:27 by ahmaymou         ###   ########.fr       */
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
	draw("j", info);
	return (0);
}

int mouse_scroll(int button, int x, int y, t_mlx_info *info)
{
	double	mouse_y;
	double	mouse_x;
	mlx_clear_window(info->mlx_ptr, info->window_ptr);
	
	mouse_x = info->xmin
		+ (x * (info->xmax - info->xmin)) / WIDTH;
	mouse_y = info->ymin
		+ (y * (info->ymax - info->ymin)) / HEIGHT;
	if (button == 4)
	{
		info->xmin = mouse_x + (info->xmin - mouse_x) / info->zoom;
		info->ymin = mouse_y + (info->ymin - mouse_y) / info->zoom;
		info->xmax = mouse_x + (info->xmax - mouse_x) / info->zoom;
		info->ymax = mouse_y + (info->ymax - mouse_y) / info->zoom;
	}
	if (button == 5)
	{
		info->xmin = mouse_x + (info->xmin - mouse_x) * info->zoom;
		info->ymin = mouse_y + (info->ymin - mouse_y) * info->zoom;
		info->xmax = mouse_x + (info->xmax - mouse_x) * info->zoom;
		info->ymax = mouse_y + (info->ymax - mouse_y) * info->zoom;
	}
	draw("j", info);
	return (info->zoom);
}

int	cross_destroy(void)
{
	exit(0);
}

int	destroy(t_mlx_info *info)
{
	mlx_destroy_image(info->mlx_ptr, info->data.img);
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
        info->offsety += 30;
    else if (key == 0)    // keycode for 'a'
       info->offsetx += 30;
	else if (key == 1)
		info->offsety -= 30; // keycode for 's'
	else if (key == 2)
		info->offsetx -= 30; // keycode for 'd'
	else if (key == 53)
		destroy(info);
	draw("j", info);
	return (0);
}

void	my_mlx_pixel_put(t_mlx_info *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data.addr + (y * data->data.line_length + x * (data->data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_mlx_info	info;

	init(&info);
	draw("j", &info);
	mlx_key_hook(info.window_ptr, change_pal, &info);
	mlx_hook(info.window_ptr, 6, 0, mouse_move, &info);
	mlx_hook(info.window_ptr, 4, 0, mouse_scroll, &info);
	mlx_hook(info.window_ptr, 17, 0, cross_destroy, &info);
	mlx_loop(info.mlx_ptr);
	return (0);
}