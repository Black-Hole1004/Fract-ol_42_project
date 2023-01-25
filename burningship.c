/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:03:15 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/25 16:33:13 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fract_ol.h"

int count_iter_burn(float complex c)
{
	float complex new_z;
	int iter = 0;
	new_z = 0;
	while (iter < MAX_ITER)
	{

		if (magnitude((int)creal(new_z), (int)cimag(new_z)) > 2)
			return (iter);
        double x = creal(new_z)*creal(new_z) - cimag(new_z)*cimag(new_z) + creal(c);
        double y = fabs(2*creal(new_z)*cimag(new_z)) + cimag(c); // abs returns the absolute value
        new_z = CMPLX(x, y);
		// new_z = creal(new_z) + cpow(cimag(new_z), 2) + c;
		iter++;
	}
	return (MAX_ITER);
}

int isInt(double num) {
    if (num - (int)num == 0) {
        return 1;
    } else {
        return 0;
    }
}

void	draw_odd(char type[], t_mlx_info *info)
{
	int i = 0;
	int j;
	// int iter;
	float complex z = CMPLX(1, 2);
	(void)type;
	unsigned int color;
	// mlx_string_put(info->mlx_ptr, info->window_ptr, 0, 0, BLUE, type);
	while (i++ < WIDTH)
		{
			j = -1;
			while (++j < HEIGHT)
			{
				z = convert(i, j, info);
				// unsigned int color = info->palettes[info->p][iter % 11];
				if (creal(z)==cimag(z) && isInt(creal(z) && (int)round(creal(z))%2==1))
				{
					color = RED;
				}
				else
					color = BLACK;
				// iter = count_iter_burn(z);
				mlx_pixel_put(info->mlx_ptr, info->window_ptr, i, j, color);
			}
		}
}

void	draw_burn(char type[], t_mlx_info *info)
{
	int i = 0;
	int j;
	int iter;
	float complex z = CMPLX(1, 2);
	mlx_string_put(info->mlx_ptr, info->window_ptr, 0, 0, BLUE, type);
	while (i++ < WIDTH)
		{
			j = -1;
			while (++j < HEIGHT)
			{
				z = convert(i, j, info);
				unsigned int color = info->palettes[info->p][iter % 11];
				iter = count_iter_burn(z);
				mlx_pixel_put(info->mlx_ptr, info->window_ptr, i, j, color);
			}
		}
}