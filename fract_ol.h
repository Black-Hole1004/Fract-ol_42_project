/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:15:40 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/27 23:02:46 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H

#include <complex.h>
#include <unistd.h>
#include <math.h>
#include "colors.h"
// #include "mlx.h"
#include "printf/ft_printf.h"
#include "libft/libft.h"
# include "mlx/mlx.h"

#define HEIGHT 			500
#define WIDTH 			500
#define DEFAULT_ZOOM 	1
#define MAX_ITER 		100

#define COLOR_FACT 		6
#define COLOR_FACT2 	230
#define COLOR_FACT3 	25
#define X_MOUSE			0
#define Y_MOUSE			0


typedef struct	s_cmp {
	double	real;
	double	imag;
}				t_cmp;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
	double		offsetx;
	double		offsety;
	int			palettes[4][10];
	int			p;
	t_cmp		fix;
	t_data		data;
}			t_mlx_info;

void			my_mlx_pixel_put(t_mlx_info *data, int x, int y, int color);
void			draw_odd(char type[], t_mlx_info *info);
void			draw_first(void *mlx_ptr, void *window_ptr, char type[], t_mlx_info *info);
int 			magnitude(double real, double imag);
int 			deal_key(int key, void *param);
int 			count_iter_jul(t_cmp c, t_cmp fix);
int 			count_iter_mand(t_cmp c);
unsigned int 	get_color(int i);
t_cmp			convert(double x, double y, t_mlx_info *info);
void			draw(char type[], t_mlx_info *info);
void 			init(t_mlx_info *info);
void			draw_burn(char type[], t_mlx_info *info);
t_cmp			convert_odd(int x, int y, t_mlx_info *info);
void    		init_palettes(t_mlx_info *info);

#endif