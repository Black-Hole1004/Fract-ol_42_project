/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:58:15 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/14 13:21:30 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd1(char c, int fd, int *len)
{
	write (fd, &c, 1);
	(*len)++;
}

int	ft_putnbr_neg(int nb, int fd, int *len, int *is_done)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(fd, "-2147483648", 11);
			*(is_done) = 1;
			(*len) += 11;
		}
		else
			ft_putchar_fd1('-', fd, len);
		nb = nb * (-1);
	}
	return (nb);
}

void	ft_putnbr_fd1(int nb, int fd, int *len, int *is_done)
{
	char	to_write[15];
	int		i;

	i = 0;
	nb = ft_putnbr_neg(nb, fd, len, is_done);
	if (!(*is_done))
	{
		if (!nb)
			ft_putchar_fd1((nb + '0'), fd, len);
		while (nb)
		{
			to_write[i++] = nb % 10 + '0';
			nb = nb / 10;
		}
		while (i--)
		{
			write(1, &to_write[i], 1);
			(*len)++;
		}
	}		
}

void	ft_putstr_fd1(char *s, int fd, int *len)
{
	if (!s)
	{
		write (1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (*s)
	{
		ft_putchar_fd1(*s, fd, len);
		s++;
	}
}
