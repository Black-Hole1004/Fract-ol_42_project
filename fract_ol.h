/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:15:40 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/28 19:30:33 by ahmaymou         ###   ########.fr       */
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

#define HEIGHT 			800
#define WIDTH 			1200
#define DEFAULT_ZOOM 	1
#define MAX_ITER 		100

#define COLOR_FACT 		6
#define COLOR_FACT2 	230
#define COLOR_FACT3 	25
#define X_MOUSE			0
#define Y_MOUSE			0


typedef struct	s_cmp
{
	double	real;
	double	imag;
}				t_cmp;

typedef struct	s_data
{
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
	double 		zoom;
	char		type[15];
	double		xmin;
	double		ymin;
	double		xmax;
	double		ymax;
	double		offsetx;
	double		offsety;
	int			p;
	t_cmp		fix;
	t_data		data;
	int			iter_max;
	int			stop;
}			t_mlx_info;

void			draw_tricorn(t_mlx_info *info);
int				count_iter_tricorn(t_cmp c, t_mlx_info *info);
int				mouse_move(int x_pos, int y_pos, t_mlx_info *info);
int				mouse_scroll(int button, int x, int y, t_mlx_info *info);
int				cross_destroy(void);
int				destroy(t_mlx_info *info);
int				change_pal(int key, t_mlx_info *info);
void    		change_col(int key, t_mlx_info *info);
void    		change_shape(int key, t_mlx_info *info);
void			draw_info(t_mlx_info *info);
void			my_mlx_pixel_put(t_data	*data, int x, int y, int color);
void			draw_julia(t_mlx_info *info);
int 			magnitude(double real, double imag);
int 			count_iter_jul(t_cmp c, t_cmp fix, t_mlx_info *info);
int 			count_iter_mand(t_cmp c, t_mlx_info *info);
t_cmp			convert(double x, double y, t_mlx_info *info);
void			draw_man(t_mlx_info *info);
void 			init(t_mlx_info *info);
void			draw_burn(t_mlx_info *info);
void    		draw_shape(t_mlx_info *info);
void			boundry_init(t_mlx_info *info);
#endif