/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupkernels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:20:14 by efleta            #+#    #+#             */
/*   Updated: 2020/11/09 18:20:16 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		set_up_kernel_mandelbrot(t_fractal *fractal, int err, cl_mem mem_img,
									cl_kernel *kernel)
{
	fractal->step_x = (fractal->right_b - fractal->left_b) /
				(float)fractal->win_w;
	fractal->step_y = -(fractal->top_b - fractal->bot_b) /
				(float)fractal->win_h;
	err = clSetKernelArg(*kernel, 0, sizeof(cl_mem), &mem_img);
	err |= clSetKernelArg(*kernel, 1, sizeof(float), &fractal->step_x);
	err |= clSetKernelArg(*kernel, 2, sizeof(float), &fractal->step_y);
	err |= clSetKernelArg(*kernel, 3, sizeof(int), &fractal->depth);
	err |= clSetKernelArg(*kernel, 4, sizeof(float), &fractal->radius);
	err |= clSetKernelArg(*kernel, 5, sizeof(float), &fractal->left_b);
	err |= clSetKernelArg(*kernel, 6, sizeof(float), &fractal->top_b);
	err |= clSetKernelArg(*kernel, 7, sizeof(int), &fractal->win_w);
	err |= clSetKernelArg(*kernel, 8, sizeof(int), &fractal->color);
	err |= clSetKernelArg(*kernel, 9, sizeof(char), &fractal->fractol);
	return (err);
}

int		set_up_kernel_julia_burning_ship(t_fractal *fractal, int err,
											cl_mem mem_img, cl_kernel *kernel)
{
	fractal->step_x = (fractal->right_b - fractal->left_b) /
				(float)fractal->win_w;
	fractal->step_y = -(fractal->top_b - fractal->bot_b) /
			(float)fractal->win_h;
	err = clSetKernelArg(*kernel, 0, sizeof(cl_mem), &mem_img);
	err |= clSetKernelArg(*kernel, 1, sizeof(float), &fractal->step_x);
	err |= clSetKernelArg(*kernel, 2, sizeof(float), &fractal->step_y);
	err |= clSetKernelArg(*kernel, 3, sizeof(int), &fractal->depth);
	err |= clSetKernelArg(*kernel, 4, sizeof(float), &fractal->radius);
	err |= clSetKernelArg(*kernel, 5, sizeof(float), &fractal->left_b);
	err |= clSetKernelArg(*kernel, 6, sizeof(float), &fractal->top_b);
	err |= clSetKernelArg(*kernel, 7, sizeof(int), &fractal->win_w);
	err |= clSetKernelArg(*kernel, 8, sizeof(int), &fractal->color);
	err |= clSetKernelArg(*kernel, 9, sizeof(char), &fractal->fractol);
	err |= clSetKernelArg(*kernel, 10, sizeof(float ), &fractal->koef_x);
	err |= clSetKernelArg(*kernel, 11, sizeof(float), &fractal->koef_y);
	return (err);
}
