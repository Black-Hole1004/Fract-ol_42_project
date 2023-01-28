/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:11:56 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/28 19:24:17 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int mouse_move(int x_pos, int y_pos, t_mlx_info *info)
{
	info->fix = convert(x_pos, y_pos, info);
    if (!ft_strncmp(info->type, "julia", 6) && !info->stop)
	    draw_shape(info);
	return (0);
}

int mouse_scroll(int button, int x, int y, t_mlx_info *info)
{
	double	mouse_y;
	double	mouse_x;

	mlx_clear_window(info->mlx_ptr, info->window_ptr);
	mouse_x = info->xmin
		+ (x * (info->xmax - info->xmin)) / 800;
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
	draw_shape(info);
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
    change_col(key, info);
    change_shape(key, info);
    if (key == 24)
    {
        if (info->iter_max <= 500)
            info->iter_max += 5;
    }
    else if (key == 27)
    {
        if (info->iter_max > 5)
            info->iter_max -= 5;
    }
    else if (key == 3)
    {
        info->stop++;
        info->stop = info->stop % 2;
    }
	draw_shape(info);
	return (0);
}