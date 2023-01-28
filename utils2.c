/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:22 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/28 19:25:11 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void    change_col(int key, t_mlx_info *info)
{
    if (key == 18)
		info->p = WHITE;
    else if (key == 19)
		info->p = LIGHTGREEN;
	else if (key == 20)
		info->p = ORANGE;
	else if (key == 21)
		info->p = RED;
	else if (key == 23)
		info->p = LIGHTBLUE;
	else if (key == 22)
		info->p = YELLOW;
	else if (key == 26)
        info->p = KHAKI;
    else if (key == 28)
        info->p = LIGHTCYAN;
    else if (key == 25)
        info->p = GRAY;
}

void    change_shape(int key, t_mlx_info *info)
{
    if (key == 46)
        ft_strlcpy(info->type, "mandelbrot", 12);
    else if (key == 38)
        ft_strlcpy(info->type, "julia", 6);
    else if (key == 11)
        ft_strlcpy(info->type, "burningship", 12);
    else if (key == 17)
        ft_strlcpy(info->type, "tricorn", 8);
    else if (key == 15)
        boundry_init(info);
	else if (key == 53)
		destroy(info);
    else if (key == 13)
        info->offsety += 0.1;
    else if (key == 0)
       info->offsetx += 0.1;
	else if (key == 1)
		info->offsety -= 0.1;
	else if (key == 2)
		info->offsetx -= 0.1;
}

void    boundry_init(t_mlx_info *info)
{
    info->offsetx = 0;
	info->offsety = 0;
    info->xmax = 2;
    info->ymax = 2;
    info->xmin = -2;
    info->ymin = -2;
    info->iter_max = MAX_ITER;
}

void init(t_mlx_info *info)
{
	info->mlx_ptr = mlx_init();
	info->window_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "fractol 42");
    info->data.img =  mlx_new_image(info->mlx_ptr, 800, HEIGHT);
	info->data.addr = mlx_get_data_addr(info->data.img, &info->data.bits_per_pixel
                    , &info->data.line_length,&info->data.endian);
	info->zoom = 1.2;
    boundry_init(info);
	info->p = WHITE;
    info->stop = 0;
    draw_info(info);
}
