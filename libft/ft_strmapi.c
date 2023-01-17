/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:40:29 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/10/25 18:51:05 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*to_return;
	int				i;

	i = 0;
	if (!s || !f)
		return (NULL);
	to_return = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!to_return)
		return (NULL);
	while (*s)
	{
		to_return[i] = f(i, *s);
		s++;
		i++;
	}
	to_return[i] = '\0';
	return (to_return);
}
