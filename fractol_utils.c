/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:05:27 by ahmaymou          #+#    #+#             */
/*   Updated: 2023/01/20 15:45:31 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// void	fractol_suiii(void)
// {
// 	ft_printf("suiiiiii");
// }

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define WIDTH 50
#define HEIGHT 50
#define XCENTER 0.0
#define YCENTER 0.0
#define XMIN -2.0
#define XMAX 2.0
#define YMIN -2
#define YMAX 2
#define MAX_ITER 50

// int main() {
//     double x, y;
//     double xmin = XMIN + XCENTER;
//     double xmax = XMAX + XCENTER;
//     double ymin = YMIN + YCENTER;
//     double ymax = YMAX + YCENTER;
//     double xstep = (xmax - xmin) / WIDTH;
//     double ystep = (ymax - ymin) / HEIGHT;
//     int value;
//     for (y = ymin; y < ymax; y += ystep) {
//         for (x = xmin; x < xmax; x += xstep) {
//             double complex c = x + y * I;
//             double complex z = 0;
//             int iterations = 0;
//             while (cabs(z) < 2 && iterations < MAX_ITER) {
//                 z = z * z + c;
//                 iterations++;
//             }
//             if (iterations == MAX_ITER) {
//                 printf("*");
//             } else {
//                 printf(" ");
//             }
//         }
//         printf("\n");
//     }
//     return 0;
// }