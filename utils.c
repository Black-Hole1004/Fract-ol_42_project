/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:05:12 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/27 21:57:44 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int magnitude(double real, double imag)
{
    return sqrt(real*real + imag*imag);
}

t_cmp   convert(double x, double y, t_mlx_info *info)
{
	t_cmp   cmp;
    (void)info;
    double a = info->xmin + ((double)(x) * (info->xmax - info->xmin)) / WIDTH;
    double b = info->ymin + ((double)(y) * (info->ymax - info->ymin)) / HEIGHT;
	cmp.real = a;
    cmp.imag = b;
    // info->offsetx = 0;
    // info->offsety = 0;
	return (cmp);
}

// double complex	convert_odd(int x, int y, t_mlx_info *info)
// {
// 	double complex	cmp;

// 	int a = (x - WIDTH/2)/WIDTH/2 * info->zoom;
// 	int b = -(y - HEIGHT/2)/HEIGHT/2 * info->zoom;
// 	cmp = CMPLX(a, b);
// 	// printf("x : %f y : %f\n", creal(cmp) , cimag(cmp));
// 	return (cmp);
// }

int	deal_key(int key, void *param)
{
	(void) param;
	(void) key;
	// if (key == 1)
	// 	mlx_destroy_window(param, param2);
	ft_printf("suiii\n");
	return (0);
}

void	draw(char type[], t_mlx_info *info)
{
    double i;
    double j;
    int iter;
    int color;
    t_cmp   z;
    i = -1;
    mlx_clear_window(info->mlx_ptr, info->window_ptr);
    while (++i < 500)
    {
        j = -1;
        while (++j < 500)
        {
            z = convert(i, j, info);
            if (iter == MAX_ITER)
                color = 0;
            else
                color = iter * 25;
            // unsigned int color = get_color(iter);
            // unsigned int color = info->palettes[info->p][iter % 11];
            if (!strncmp(type, "mandelbrot", 11))
                iter = count_iter_mand(z);
            else
                iter = count_iter_jul(z, info->fix);
            my_mlx_pixel_put(info, i, j, color);
            // mlx_pixel_put(info->mlx_ptr, info->window_ptr, i, j, color);
        }
    }
	mlx_put_image_to_window(info->mlx_ptr, info->window_ptr, info->data.img, 0, 0);
    // mlx_string_put(info->mlx_ptr, info->window_ptr, 250, 30, BLUE, "mouse_x :30 mouse_y : 40");
}

void    init_palettes(t_mlx_info *info)
{
    int **palettes = malloc(4 * sizeof(int*));
	int palette4[] = {C41, BLACK, C43, C44, C45, C46, C47, C48,C49,C410,C411};
	int palette1[] = {C11 ,BLACK, C13, C14, C15, C16, C17, C18,C19,C110,C111};
	int palette2[] = {C21, BLACK, C23, C24, C25, C26, C27, C28,C29,C210,C211};
	int palette3[] = {C31, BLACK, C33, C34, C35, C36, C37, C38,C39,C310,C311};
    palettes[0] = palette1;
    palettes[1] = palette2;
    palettes[2] = palette3;
    palettes[3] = palette4;
    for (int i = 0;i < 4;i++)
		for (int j = 0;j < 11;j++)
			info->palettes[i][j] = palettes[i][j];
    free(palettes);
}

void init(t_mlx_info *info)
{
	info->mlx_ptr = mlx_init();
	info->window_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "fractol 42");
    info->data.img =  mlx_new_image(info->mlx_ptr, 500, HEIGHT);
	info->data.addr = mlx_get_data_addr(info->data.img, &info->data.bits_per_pixel, &info->data.line_length,&info->data.endian);
    init_palettes(info);
	info->zoom = 1.2;
	info->height = HEIGHT;
	info->width = WIDTH;
	info->offsetx = 0;
	info->offsety = 0;
    info->xmax = 2;
    info->ymax = 2;
    info->xmin = -2;
    info->ymin = -2;
	info->p = 0;
    // info->fix = CMPLX(0, 0);
}
