/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:14:41 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/17 18:25:25 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int count_iter_jul(float complex c, float complex fix)
{
	float complex new_z;
	int iter = 0;

	new_z = c;
	while (iter < MAX_ITER)
	{
		if (magnitude((int)creal(new_z), (int)cimag(new_z)) > 2)
			return (iter);
		new_z = cpowf(new_z, 2) + fix;
		iter++;
	}
	return (MAX_ITER);
}