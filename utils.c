/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:05:12 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/21 20:37:38 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int magnitude(int real, int imag) {
    return sqrt(real*real + imag*imag);
}

double complex	convert(int x, int y, t_mlx_info *info)
{
	double complex	cmp;

	double a = ((double)x - info->mouse_x - WIDTH/2)/WIDTH/2 * info->zoom;
	double b = -((double)y + info->mouse_y - HEIGHT/2)/HEIGHT/2 * info->zoom;
	cmp = CMPLX(a, b);
	// printf("x : %f y : %f\n", creal(cmp) , cimag(cmp));
	return (cmp);
}

double complex	convert_odd(int x, int y, t_mlx_info *info)
{
	double complex	cmp;

	int a = (x + info->mouse_x - WIDTH/2)/WIDTH/2 * info->zoom;
	int b = -(y + info->mouse_y - HEIGHT/2)/HEIGHT/2 * info->zoom;
	cmp = CMPLX(a, b);
	// printf("x : %f y : %f\n", creal(cmp) , cimag(cmp));
	return (cmp);
}

int	deal_key(int key, void *param)
{
	(void) param;
	(void) key;
	// if (key == 1)
	// 	mlx_destroy_window(param, param2);
	ft_printf("suiii\n");
	return (0);
}
// #define XCENTER 0.0
// #define YCENTER 0.0
// #define XMIN -2.0
// #define XMAX 2.0
// #define YMIN -2
// #define YMAX 2

// int main() {
//     double x, y;
//     double xmin = XMIN + XCENTER;
//     double xmax = XMAX + XCENTER;
//     double ymin = YMIN + YCENTER;
//     double ymax = YMAX + YCENTER;
//     double xstep = (xmax - xmin) / WIDTH;
//     double ystep = (ymax - ymin) / HEIGHT;
//     int value;
//     for (y = ymin; y < ymax; y += ystep) {
//         for (x = xmin; x < xmax; x += xstep) {
//             double complex c = x + y * I;
void	draw(void *mlx_ptr, void *window_ptr, char type[], t_mlx_info *info)
{
	double i = 0;
	double j;
    // double x, y;
    // double xmin = XMIN + XCENTER;
    // double xmax = XMAX + XCENTER;
    // double ymin = YMIN + YCENTER;
    // double ymax = YMAX + YCENTER;
    // double xstep = (xmax - xmin) / WIDTH;
    // double ystep = (ymax - ymin) / HEIGHT;
	int iter;
	float complex z = CMPLX(1, 2);
	mlx_string_put(mlx_ptr, window_ptr, 0, 0, 0x0, type);
	while (i++ < WIDTH)
		{
			j = -1;
			while (++j < HEIGHT)
			{
				z = convert(i, j, info);
				// z = CMPLX(i, j);
				// unsigned int color = get_color(iter);
				// printf("%.2f %.2f\n", creal(z), cimag(z));
				unsigned int color = info->palette[info->p][iter % 11];
				if (!strncmp(type, "mandelbrot", 11))
				{
					iter = count_iter_mand(z);
					mlx_pixel_put(mlx_ptr, window_ptr, i, j, color);
				}
				// unsigned int color = palette[iter % 10];
	/*=======================================   julia   ===================================*/
				else{
					double complex fix = CMPLX(-0.4, -0.6);
					iter = count_iter_jul(z, fix);
					mlx_pixel_put(mlx_ptr, window_ptr, i, j, color);
				}
			}
		}
}

void init(t_mlx_info *info, int **palettes)
{
	info->mlx_ptr = mlx_init();
	info->window_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "fractol 42");
	info->zoom = DEFAULT_ZOOM;
	info->height = HEIGHT;
	info->width = WIDTH;
	info->mouse_x = 0;
	info->mouse_y = 0;
	for (int i = 0;i < 4;i++)
		for (int j = 0;j < 11;j++)
			info->palette[i][j] = palettes[i][j];
	info->p = 0;
}
