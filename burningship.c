/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:03:15 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/29 16:21:25 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	count_iter_burn(t_cmp c, t_mlx_info *info)
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
		temp = new_z.real * new_z.real - new_z.imag * new_z.imag - c.real;
		new_z.imag = fabs(2 * new_z.real * new_z.imag) + c.imag;
		new_z.real = temp;
		iter++;
	}
	return (info->iter_max);
}

void	draw_burn(t_mlx_info *info)
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
			iter = count_iter_burn(z, info);
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
