/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:14:41 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/28 15:37:37 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int count_iter_jul(t_cmp c, t_cmp fix, t_mlx_info *info)
{
	t_cmp	new_z;
	double	temp;
	int iter = 0;

	new_z = c;
	while (iter < info->iter_max)
	{
		if (magnitude(new_z.real, new_z.imag) >= 2)
			return (iter);
		temp = new_z.real;
		new_z.real = new_z.real * new_z.real - new_z.imag * new_z.imag - fix.real;
		new_z.imag = 2 * new_z.imag * temp + fix.imag;
		iter++;
	}
	return (info->iter_max);
}

void	draw_julia(t_mlx_info *info)
{
    double  i;
    double  j;
    int     iter;
    int     color;
    t_cmp   z;

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
            iter = count_iter_jul(z, info->fix, info);
            my_mlx_pixel_put(&info->data, i, j, color);
        }
    }
	mlx_put_image_to_window(info->mlx_ptr, info->window_ptr, info->data.img, 0, 0);
}