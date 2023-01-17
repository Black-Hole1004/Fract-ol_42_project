/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:52:22 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/10/26 11:23:06 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s, const void *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *)s;
	s4 = (unsigned char *)s2;
	while (n--)
	{
		if (*s3 - *s4 != 0)
			return (*s3 - *s4);
		s3++;
		s4++;
	}
	return (0);
}
