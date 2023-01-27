/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   odds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:03:15 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/27 23:13:46 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fract_ol.h"

int count_iter_burn(t_cmp c)
{
	t_cmp   new_z;
    double  temp;
	int iter = 0;
	new_z.real = 0;
    new_z.imag = 0;
	while (iter < MAX_ITER)
	{
		if (magnitude(new_z.real, new_z.imag) > 4)
			return (iter);
        temp = new_z.real*new_z.real - new_z.imag*new_z.imag + c.real;
        new_z.imag = fabs(2*new_z.real*new_z.imag) + c.imag; // abs returns the absolute value
        new_z.real = temp;
        // new_z.real = x;
        // new_z.imag = y;
		iter++;
	}
	return (MAX_ITER);
}

void	draw_burn(char type[], t_mlx_info *info)
{
	int     i = -1;
	int     j;
	int     iter = 0;
	t_cmp   z;
    // int     color;
    (void)type;
	// mlx_string_put(mlx_ptr, window_ptr, 0, 0, BLUE, type);
	while (++i < WIDTH)
		{
			j = -1;
			while (++j < HEIGHT)
			{
				z = convert(i, j, info);
                // if (iter == MAX_ITER)
                //     color = 0;
                // else
                //     color = 0XFFFFFF;
                // printf("iter %d\n", iter);
				iter = count_iter_burn(z);
				unsigned int color = info->palettes[0][iter % 10];
				mlx_pixel_put(info->mlx_ptr, info->window_ptr, i, j, color);
		    }
        }
    mlx_put_image_to_window(info->mlx_ptr, info->window_ptr, info->data.img, 0, 0);
}