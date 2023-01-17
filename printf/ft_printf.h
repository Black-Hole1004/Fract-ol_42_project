/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:18:35 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/12/14 13:19:57 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE_16_LOWER  "0123456789abcdef"
# define BASE_16_UPPER  "0123456789ABCDEF"

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	print_normal(char str, va_list argptr, int *len);
void	ft_putnbr_ubase(unsigned int nb, int *len);
void	ft_putnbr_base(size_t nb, int *len, int X);
void	ft_putchar_fd1(char c, int fd, int *len);
void	ft_putnbr_fd1(int nb, int fd, int *len, int *is_done);
void	ft_putstr_fd1(char *s, int fd, int *len);
void	ft_putnbr_fd_unsigned(unsigned int nb, int fd, int *len);

#endif
