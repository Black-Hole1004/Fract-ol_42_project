/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   odds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:03:15 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/21 19:31:03 by ahmaymou         ###   ########.fr       */
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

void	draw_odd(void *mlx_ptr, void *window_ptr, char type[], t_mlx_info *info)
{
	int i = 0;
	int j;
    // double x, y;
    // double xmin = XMIN + XCENTER;
    // double xmax = XMAX + XCENTER;
    // double ymin = YMIN + YCENTER;
    // double ymax = YMAX + YCENTER;
    // double xstep = (xmax - xmin) / WIDTH;
    // double ystep = (ymax - ymin) / HEIGHT;
	int iter;
	float complex z = CMPLX(1, 2);
	mlx_string_put(mlx_ptr, window_ptr, 0, 0, BLUE, type);
	while (i++ < WIDTH)
		{
			j = -1;
			while (++j < HEIGHT)
			{
				z = convert(i, j, info);
				// z = CMPLX(i, j);
				// unsigned int color = get_color(iter);
				// printf("%.2f %.2f\n", creal(z), cimag(z));
				unsigned int color = info->palette[0][iter % 10];
				iter = count_iter_burn(z);
				mlx_pixel_put(mlx_ptr, window_ptr, i, j, color);
		}
}
}