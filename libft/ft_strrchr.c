/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:25:11 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/10/26 18:27:45 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_occurences(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int				occurence;
	unsigned char	c1;

	c1 = c;
	occurence = count_occurences(s, c1);
	if (c1 == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s && occurence)
	{
		if (*s == c1 && occurence == 1)
			return ((char *)s);
		if (*s == c1)
			occurence--;
	s++;
	}
	return (NULL);
}
