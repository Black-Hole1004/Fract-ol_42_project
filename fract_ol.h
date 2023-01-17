/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:15:40 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/17 20:21:46 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <complex.h>
# include <unistd.h>
# include <math.h>
# include "colors.h"
# include "mlx.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"

# define HEIGHT       1000
# define WIDTH          1000
# define DEFAULT_ZOOM   10
# define MAX_ITER       100
# define COLOR_FACT     5
# define COLOR_FACT2    240
# define COLOR_FACT3    30

int magnitude(int real, int imag);
double complex	convert(int x, int y);
int	deal_key(int key, void *param);
int count_iter_jul(float complex c, float complex fix);
int count_iter_mand(float complex c);

#endif