/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:53:25 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/10/26 11:23:03 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;

	buff = (unsigned char *)s;
	while (n--)
	{
		if ((unsigned char) c == *buff)
			return (buff);
		buff++;
	}
	return (NULL);
}
