/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:05:12 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/29 16:55:39 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	magnitude(double real, double imag)
{
	return (sqrt(real * real + imag * imag));
}

t_cmp	convert(double x, double y, t_mlx_info *info)
{
	t_cmp	cmp;
	double	a;
	double	b;

	(void)info;
	a = info->xmin + info->offsetx + ((double)x
			* (info->xmax - info->xmin)) / 800;
	b = info->ymin + info->offsety + ((double)y
			* (info->ymax - info->ymin)) / HEIGHT;
	cmp.real = a;
	cmp.imag = b;
	return (cmp);
}

void	draw_shape(t_mlx_info *info)
{
	mlx_clear_window(info->mlx_ptr, info->window_ptr);
	draw_info(info);
	if (!ft_strncmp(info->type, "mandelbrot", 11))
		draw_man(info);
	else if (!ft_strncmp(info->type, "julia", 6))
		draw_julia(info);
	else if (!ft_strncmp(info->type, "burningship", 12))
		draw_burn(info);
	else if (!ft_strncmp(info->type, "tricorn", 8))
		draw_tricorn(info);
}

void	put_strings(t_mlx_info *info)
{
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 30, YELLOW, "------------------------------");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 50, YELLOW, "move up          : <w>");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 90, YELLOW, "move left        : <a>");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 130, YELLOW, "move right       : <d>");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 170, YELLOW, "move down        : <s>");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 190, YELLOW, "------------------------------");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 210, YELLOW, "change colors    :");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 250, YELLOW, "WHITE            : 1 ");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 280, YELLOW, "LIGHTGREEN       : 2 ");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 310, YELLOW, "ORANGE           : 3 ");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 340, YELLOW, "RED              : 4");
	put_strings2(info);
}

void	draw_info(t_mlx_info *info)
{
	char	*iters;
	char	*itoa;

	draw_info_back(info);
	itoa = ft_itoa(info->iter_max);
	iters = ft_strjoin("MAX ITERS        : ", itoa);
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 10, YELLOW, "Zoom             : mouse scroll");
	put_strings(info);
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 660, YELLOW, "------------------------------");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 680, YELLOW, "add/reduce iters : +/-");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 710, YELLOW, "Reset params     : r");
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 740, YELLOW, iters);
	free(iters);
	free(itoa);
	mlx_string_put(info->mlx_ptr, info->window_ptr,
		830, 770, YELLOW, "Destroy window   : ESC");
}
