/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:26:42 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/10/26 17:05:12 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(long nbr)
{
	int		b;

	b = 0;
	if (!nbr)
		b = 1;
	else if (nbr < 0)
	{
		nbr *= (-1);
		b++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		b++;
	}
	return (b);
}

static char	*ft_convert(long nbr, char *s, int lennbr)
{
	if (nbr < 0)
	{
		nbr *= (-1);
		s[0] = '-';
	}
	else if (!nbr)
		s[0] = '0';
	while (nbr != 0)
	{
		s[lennbr] = (nbr % 10) + '0';
		nbr = nbr / 10;
		lennbr--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int			lennbr;
	int			nbr;
	char		*s;

	nbr = n;
	lennbr = ft_get_len(nbr) - 1;
	s = (char *)malloc((lennbr + 2) * sizeof(char));
	if (!s)
		return (NULL);
	s[lennbr + 1] = '\0';
	s = ft_convert(nbr, s, lennbr);
	return (s);
}
