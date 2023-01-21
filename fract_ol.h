/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:15:40 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/21 19:54:06 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H

#include <complex.h>
#include <unistd.h>
#include <math.h>
#include "colors.h"
#include "mlx.h"
#include "printf/ft_printf.h"
#include "libft/libft.h"

#define HEIGHT 			600
#define WIDTH 			600
#define DEFAULT_ZOOM 	8
#define MAX_ITER 		100
#define COLOR_FACT 		6
#define COLOR_FACT2 	230
#define COLOR_FACT3 	25
#define X_MOUSE			0
#define Y_MOUSE			0
typedef struct s_mlx_info
{
	void 		*mlx_ptr;
	void 		*window_ptr;
	unsigned int height;
	unsigned int width;
	double 		zoom;
	char		*type;
	int			mouse_x;
	int			mouse_y;
	double		xmin;
	double		ymin;
	double		xmax;
	double		ymax;
	int			palette[4][10];
	int			p;
}			t_mlx_info;

int magnitude(int real, int imag);
int deal_key(int key, void *param);
int count_iter_jul(float complex c, float complex fix);
int count_iter_mand(float complex c);
unsigned int get_color(int i);
double complex	convert(int x, int y, t_mlx_info *info);
void	draw(void *mlx_ptr, void *window_ptr, char type[], t_mlx_info *info);
void 	init(t_mlx_info *info, int **palette);
void	draw_odd(void *mlx_ptr, void *window_ptr, char type[], t_mlx_info *info);
double complex	convert_odd(int x, int y, t_mlx_info *info);

#endif