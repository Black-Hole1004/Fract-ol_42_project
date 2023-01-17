/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:17:57 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/14 13:21:11 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_unsigned(unsigned int nb, int fd, int *len)
{
	char	to_write[15];
	int		i;

	i = 0;
	if (!nb)
		ft_putchar_fd1((nb + '0'), fd, len);
	while (nb)
	{
		to_write[i++] = BASE_16_LOWER[nb % 10];
		nb = nb / 10;
	}
	while (i--)
	{
		write(1, &to_write[i], 1);
		(*len)++;
	}
}

void	ft_putnbr_base(size_t nb, int *len, int X)
{
	int		i;
	char	to_write[20];

	i = 0;
	if (X == 'p')
		ft_putstr_fd1("0x", 1, len);
	else
		nb = (unsigned int)nb;
	if (!nb)
		ft_putchar_fd1((nb + '0'), 1, len);
	while (nb)
	{
		to_write[i++] = BASE_16_LOWER[nb % 16];
		nb = nb / 16;
	}
	while (i--)
		ft_putchar_fd1(to_write[i], 1, len);
}

void	ft_putnbr_ubase(unsigned int nb, int *len)
{
	char	to_write[15];
	int		i;

	i = 0;
	if (!nb)
		ft_putchar_fd1((nb + '0'), 1, len);
	while (nb)
	{
		to_write[i++] = BASE_16_UPPER[nb % 16];
		nb = nb / 16;
	}
	while (i--)
	{
		write(1, &to_write[i], 1);
		(*len)++;
	}
}

void	print_normal(char str, va_list argptr, int *len)
{
	int	is_done;

	is_done = 0;
	if (str == 'd' || str == 'i')
		ft_putnbr_fd1(va_arg(argptr, int), 1, len, &is_done);
	else if (str == 'c')
		ft_putchar_fd1(va_arg(argptr, int), 1, len);
	else if (str == 's')
		ft_putstr_fd1(va_arg(argptr, char *), 1, len);
	else if (str == 'p')
		ft_putnbr_base(va_arg(argptr, size_t), len, str);
	else if (str == 'x')
		ft_putnbr_base(va_arg(argptr, size_t), len, str);
	else if (str == 'X')
		ft_putnbr_ubase(va_arg(argptr, unsigned int), len);
	else if (str == '%')
		ft_putchar_fd1('%', 1, len);
	else if (str == 'u')
		ft_putnbr_fd_unsigned(va_arg(argptr, unsigned int), 1, len);
	else
		ft_putchar_fd1(str, 1, len);
}
