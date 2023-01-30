/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:02:02 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/30 20:16:35 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	error(void)
{
	ft_printf("\033[31mIncorrect format: ./fractol <Shape name>: mandelbrot,");
	ft_printf(" julia, burningship, tricorn !\n\033[0m");
	exit(1);
}

int	pars(char *string, t_mlx_info *info)
{
	int	i;

	i = -1;
	while (string[++i])
		string[i] = ft_tolower(string[i]);
	if (!ft_strncmp(string, "mandelbrot", 12))
		ft_strlcpy(info->type, "mandelbrot", 12);
	else if (!ft_strncmp(string, "julia", 6))
		ft_strlcpy(info->type, "julia", 6);
	else if (!ft_strncmp(string, "burningship", 12))
		ft_strlcpy(info->type, "burningship", 12);
	else if (!ft_strncmp(string, "tricorn", 8))
		ft_strlcpy(info->type, "tricorn", 9);
	else
		return (-1);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	leaks(void)
{
	system("leaks fractol");
}

int	main(int argc, char **argv)
{
	t_mlx_info	info;

	if (argc != 2)
		error();
	if (pars(argv[1], &info) == -1)
		error();
	init(&info);
	draw_shape(&info);
	mlx_key_hook(info.window_ptr, change_pal, &info);
	mlx_hook(info.window_ptr, 6, 0, mouse_move, &info);
	mlx_hook(info.window_ptr, 4, 0, mouse_scroll, &info);
	mlx_hook(info.window_ptr, 17, 0, cross_destroy, &info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
