/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:18:19 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/14 13:44:37 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		len;

	len = 0;
	va_start(argptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!(*str))
				break ;
			print_normal(*str, argptr, &len);
		}
		else
			ft_putchar_fd1(*str, 1, &len);
		str++;
	}
	va_end(argptr);
	return (len);
}

// int main()
// {
// 	//int x = 0;
// 	//printf("%%%%%%%%");
// 	//ft_printf("%p\t%x", &x, 1123455555);
// }
