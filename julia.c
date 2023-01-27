/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:14:41 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/27 21:56:55 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int count_iter_jul(t_cmp c, t_cmp fix)
{
	t_cmp	new_z;
	double	temp;
	int iter = 0;

	new_z = c;
	while (iter < MAX_ITER)
	{
		if (magnitude(new_z.real, new_z.imag) >= 2)
			return (iter);
		temp = new_z.real;
		new_z.real = new_z.real * new_z.real - new_z.imag * new_z.imag - fix.real;
		new_z.imag = 2 * new_z.imag * temp + fix.imag;
		iter++;
	}
	return (MAX_ITER);
}