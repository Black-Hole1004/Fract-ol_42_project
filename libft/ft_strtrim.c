/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:21:30 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/10/26 16:37:46 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char *set, const char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
	i++;
	}
	return (0);
}

static char	*trim_first(const char *s, const char *set)
{
	while (*s && is_set(set, *s))
		s++;
	return ((char *)s);
}

static size_t	trim_last(const char *s, const char *set, size_t len_s1)
{
	char	*temp;

	temp = (char *)s;
	while (is_set(set, temp[len_s1 - 1]) && len_s1)
		len_s1--;
	return (len_s1 + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	len_s1;
	char			*to_return;

	if (!s1 || !set)
		return (NULL);
	s1 = trim_first(s1, set);
	len_s1 = trim_last(s1, set, ft_strlen(s1));
	to_return = (char *)malloc((len_s1) * sizeof(char));
	if (!to_return)
		return (NULL);
	ft_strlcpy(to_return, s1, len_s1);
	return (to_return);
}
