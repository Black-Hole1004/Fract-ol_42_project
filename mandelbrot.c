/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:12:48 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/29 16:29:48 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	count_iter_mand(t_cmp c, t_mlx_info *info)
{
	t_cmp	new_z;
	double	temp;
	int		iter;

	iter = 0;
	new_z.real = 0;
	new_z.imag = 0;
	while (iter < info->iter_max)
	{
		if (magnitude(new_z.real, new_z.imag) >= 2)
			return (iter);
		temp = new_z.real;
		new_z.real = new_z.real * new_z.real - new_z.imag * new_z.imag + c.real;
		new_z.imag = 2 * new_z.imag * temp + c.imag;
		iter++;
	}
	return (info->iter_max);
}

void	draw_man(t_mlx_info *info)
{
	double	i;
	double	j;
	int		iter;
	int		color;
	t_cmp	z;

	i = -1;
	while (++i < 800)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			z = convert(i, j, info);
			if (iter == info->iter_max)
				color = 0;
			else
				color = iter * info->p;
			iter = count_iter_mand(z, info);
			my_mlx_pixel_put(&info->data, i, j, color);
		}
	}
	mlx_put_image_to_window(info->mlx_ptr, info->window_ptr,
		info->data.img, 0, 0);
}
