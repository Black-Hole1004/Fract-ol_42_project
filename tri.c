/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:10:17 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/29 16:55:54 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	count_iter_tricorn(t_cmp c, t_mlx_info *info)
{
	t_cmp	new_z;
	t_cmp	c1;
	int		iter;
	double	temp;

	iter = 0;
	new_z.real = 0;
	new_z.imag = 0;
	while (iter < info->iter_max)
	{
		c1.real = c.real / (c.real * c.real + c.imag * c.imag);
		c1.imag = c.imag / (c.real * c.real + c.imag * c.imag);
		if (magnitude(new_z.real, new_z.imag) >= 2)
			return (iter);
		temp = new_z.real;
		new_z.real = new_z.real * new_z.real - new_z.imag
			* new_z.imag + c1.real;
		new_z.imag = 2 * new_z.imag * temp - c1.imag;
		iter++;
	}
	return (info->iter_max);
}

void	draw_tricorn(t_mlx_info *info)
{
	int		i;
	int		j;
	int		iter;
	t_cmp	z;
	int		color;

	iter = 0;
	i = -1;
	while (++i < 800)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			z = convert(i, j, info);
			iter = count_iter_tricorn(z, info);
			if (iter == info->iter_max)
				color = 0;
			else
				color = iter * info->p;
			my_mlx_pixel_put(&info->data, i, j, color);
		}
	}
	mlx_put_image_to_window(info->mlx_ptr, info->window_ptr,
		info->data.img, 0, 0);
}

void	draw_info_back(t_mlx_info *info)
{
	int		i;
	int		j;

	i = 799;
	j = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			mlx_pixel_put(info->mlx_ptr, info->window_ptr, i, j, BLUE);
	}
}
