/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:12:48 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/27 21:52:43 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int count_iter_mand(t_cmp c)
{
	t_cmp	new_z;
	double	temp;
	int iter = 0;
	new_z.real = 0;
	new_z.imag = 0;
	while (iter < MAX_ITER)
	{
		if (magnitude(new_z.real, new_z.imag) >= 2)
			return (iter);
		temp = new_z.real;
		new_z.real = new_z.real * new_z.real - new_z.imag * new_z.imag + c.real;
		new_z.imag = 2 * new_z.imag * temp + c.imag;
		iter++;
	}
	return (MAX_ITER);
}
