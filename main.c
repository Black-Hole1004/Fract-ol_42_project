/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:02:02 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/17 21:31:43 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// unsigned int get_color(int i){
//     if (i == 100) {
//         return 0; // black color
//     }
//     return (unsigned char)(i * 2.55);
// }
struct RGB {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

unsigned int get_color(int i) {
    struct RGB color;
	unsigned int c  = 0;
    if (i == MAX_ITER) {
        color.r = 0;
        color.g = 0;
        color.b = 0;
    } else {
        color.b = (unsigned char)(i * 2.55);
        color.r = (unsigned char)(100 - (i * 2.55));
        color.g = (unsigned char)(i * 5);
    }
	c += (color.r << 16) + (color.g << 8) + color.b;
    return c;
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
			unsigned int color = get_color(iter);
			mlx_pixel_put(mlx_ptr, window_ptr, i, j, color);
/*=======================================   julia   ===================================*/
			// double complex fix = -0.5;
			// iter = count_iter_jul(z, fix);
			// color = get_color(iter);
			// mlx_pixel_put(mlx_ptr, window_ptr, i, j, color);
		}
	}
	// mlx_key_hook(window_ptr, deal_key, (void *) 0);
	mlx_loop(mlx_ptr);
	return (0);
}
