/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:05:12 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/17 20:10:23 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int magnitude(int real, int imag) {
    return sqrt(real*real + imag*imag);
}

double complex	convert(int x, int y)
{
	double complex	cmp;

	double a = ((double)x - WIDTH/2)/WIDTH/2 * DEFAULT_ZOOM;
	double b = -((double)y - HEIGHT/2)/HEIGHT/2 * DEFAULT_ZOOM;
	cmp = CMPLX(a, b);
	printf("x : %.2f y : %.2f\n", creal(cmp) , cimag(cmp));
	return (cmp);
}

int	deal_key(int key, void *param)
{
	(void)param;
	(void)key;
	ft_printf("suiii\n");
	return (0);
}

