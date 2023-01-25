/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:12:48 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/25 17:59:37 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int count_iter_mand(float complex c)
{
	float complex new_z;
	int iter = 0;
	new_z = 0;
	while (iter < MAX_ITER)
	{
		if (magnitude((int)creal(new_z), (int)cimag(new_z)) > 2)
			return (iter);
		new_z = cpowf(new_z, 2) + c;
		iter++;
	}
	return (MAX_ITER);
}
