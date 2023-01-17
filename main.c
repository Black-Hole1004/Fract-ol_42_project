/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:02:02 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/17 20:11:57 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

unsigned int	colormagic(int i, double x, double y)
{
	unsigned int	color;
	double			magic;
	double			i2;
	unsigned char	c;
	unsigned char	c1;
	unsigned char	c2;

	magic = sqrt(x*x + y*y);
	i2 = i + 1 - (log(2) / magic) / log(2);
	c = (unsigned char)(sin(0.026 * i2 + COLOR_FACT) * COLOR_FACT2 + COLOR_FACT3);
	c1 = (unsigned char)(sin(0.023 * i2 + COLOR_FACT-1) * COLOR_FACT2 + COLOR_FACT3);
	c2 = (unsigned char)(sin(0.01 * i2 + COLOR_FACT-2) * COLOR_FACT2 + COLOR_FACT3);
	color = (c << 16) + (c1 << 8) + (c2 + 255);
	return (color);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*window_ptr;

	int i = 0;
	int j = 0;
	// int palette[10] = {BLACK,
	// RED,
	// ORANGERED,
	// DARKORANGE,
	// ORANGE,
	// BLUE,
	// LIGHTBLUE,
	// DARKGREEN,
	// GREEN,
	// LIGHTGREEN };
	// int red;
	// int blue;
	// int green;
	// int color = 0;
	float complex z = CMPLX(1, 2);
	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "fractol 42");
	while (i++ < WIDTH)
	{
		j = 0;
		while (++j < HEIGHT)
		{
			z = convert(i, j);
			// printf("mag :%d x :%f y :%f \n", magnitude((int)creal(z), (int)cimag(z)), creal(z), cimag(z));
			int iter = count_iter_mand(z);
			unsigned int color = colormagic(iter, creal(z), cimag(z));
			// mlx_pixel_put(mlx_ptr, window_ptr, i, j, color);
/*=======================================   julia   ===================================*/
			double complex fix = CMPLX(0.10, -1.465);
			iter = count_iter_jul(z, fix);
			color = colormagic(iter, creal(z), cimag(z));
			mlx_pixel_put(mlx_ptr, window_ptr, i, j, color);
		}
	}
	// mlx_key_hook(window_ptr, deal_key, (void *) 0);
	mlx_loop(mlx_ptr);
	return (0);
}
