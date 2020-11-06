/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:54:04 by efleta            #+#    #+#             */
/*   Updated: 2020/11/02 21:54:06 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include  <mlx.h>

//int key_events(int key, void *l)
//{
//	t_fractal *st;
//
//	st = (t_fractal *)l;
//	printf("key = %d\n", key);
//	if (key == 53)
//	{
//		mlx_destroy_window(st->mlx, st->win);
//		exit(0);
//	}
//	else if (key == 28)
//	{
//		st->depth *=2;
//		render(st);
//	}
//	else if (key == 125)
//	{
//		st->widht += 10 / st->zoom;
//		st->height += 10 / st->zoom;
//		st->x_step /= 1.2;
//		st->y_step /= 1.2;
//		st->x_step /= 1.2;
//		st->y_step /= 1.2;
//		st->x_c += 50;
//		render(st);
//	}
//	else if (key == 124)
//	{
//		st->widht += 10 / st->zoom;
//		render(st);
//	}
//	else if (key == 123)
//	{
//		st->widht -= 10 / st->zoom;
//		render(st);
//	}
//	else if (key == 126)
//	{
//		st->height -= 10 / st->zoom;
//		render(st);
//	}
//	return 0;
//}

int mouse_events(int event, int x, int y, t_fractal *fractal)
{
	float	comp_x;
	float	comp_y;
	float	dx;
	float	dy;

	dx = (fractal->right_b - fractal->left_b);
	dy = (fractal->top_b - fractal->bot_b);
	if (event == 4 || event == 6)
	{
		comp_x = dx / (float)fractal->win_w * (float)x;
		comp_y = dy / (float)fractal->win_h * (float)y;
		fractal->left_b = fractal->left_b + comp_x / 100;
		fractal->right_b = fractal->right_b - (dx - comp_x) / 100;
		fractal->top_b = fractal->top_b - comp_y / 100;
		fractal->bot_b = fractal->bot_b + (dy - comp_y) / 100;
	}
	else if (event == 5 || event == 7)
	{
		comp_x = dx / 8;
		comp_y = dy / 8;
		fractal->left_b -= comp_x;
		fractal->right_b += comp_x;
		fractal->top_b += comp_y;
		fractal->bot_b -= comp_y;
	}
	return (0);
}

void	cl_setup_program(t_cl **cl)
{
	*cl = cl_setup((char *[]){"src/mandelbrot.cl", NULL},
				(char *[]){"mandelbrot", NULL}, NULL);
}

int		render(t_fractal *fractal)
{
	float		step_x;
	float		step_y;
	int			err;
	cl_mem		mem_img;
	cl_kernel	*kernel;
	size_t		global_size;

	mem_img = clCreateBuffer(*fractal->cl->context, CL_MEM_READ_WRITE,
						fractal->win_w * fractal->win_h * sizeof(int), NULL, &err);
	if (err != 0)
		printf("create buffer - error\n");

	kernel = cl_get_kernel_by_name(fractal->cl, "mandelbrot");

	global_size = fractal->win_w * fractal->win_h;

	step_x = (fractal->right_b - fractal->left_b) / (float)fractal->win_w;
	step_y = -(fractal->top_b - fractal->bot_b) / (float)fractal->win_h;

	err = clSetKernelArg(*kernel, 0, sizeof(cl_mem), &mem_img);
	err |= clSetKernelArg(*kernel, 1, sizeof(float), &step_x);
	err |= clSetKernelArg(*kernel, 2, sizeof(float), &step_y);
	err |= clSetKernelArg(*kernel, 3, sizeof(int), &fractal->depth);
	err |= clSetKernelArg(*kernel, 4, sizeof(float), &fractal->radius);
	err |= clSetKernelArg(*kernel, 5, sizeof(float), &fractal->left_b);
	err |= clSetKernelArg(*kernel, 6, sizeof(float), &fractal->top_b);
	err |= clSetKernelArg(*kernel, 7, sizeof(int), &fractal->win_w);
//	err |= clSetKernelArg(kernel, 8, sizeof(int), &fractal->color_mult);
	if (err != 0)
		printf("set kernel arg - error\n");
	err = clEnqueueNDRangeKernel(*fractal->cl->queue, *kernel, 1, NULL, &global_size,
								 NULL, 0, NULL, NULL);
	if (err != 0)
		printf("NDR - error\n");
	err = clEnqueueReadBuffer(*fractal->cl->queue, mem_img, CL_TRUE, 0,
						   fractal->win_w * fractal->win_h * sizeof(int), fractal->img_int,
							  0, NULL, NULL);
	if (err != 0)
		printf("read buffer - error\n");
//	mlx_clear_window(fractal->mlx, fractal->win);

//	i = -1;
//	while (++i < fractal->win_w)
//	{
//		j = -1;
//		while (++j < fractal->win_h)
//			mandelbrot(fractal->img_int, i, j, step_x, step_y, fractal->depth, fractal->radius,
//			  fractal->left_b, fractal->top_b, fractal->win_w);
//	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img_ptr, 0, 0);
	return (1);
}

int		init(t_fractal *fractal)
{
	cl_setup_program(&fractal->cl);
	fractal->mlx = mlx_init();
	fractal->win_w = 1600;
	fractal->win_h = 1600;
	fractal->depth = 2000;
	fractal->radius = 3.f;
	fractal->left_b = -2.f;
	fractal->right_b = 2.f;
	fractal->bot_b = -2.f;
	fractal->top_b = 2.f;
	fractal->win = mlx_new_window(fractal->mlx, fractal->win_w, fractal->win_h, "title");
	fractal->img_ptr = mlx_new_image(fractal->mlx, fractal->win_w, fractal->win_h);
	fractal->img_int = (int *)mlx_get_data_addr(fractal->img_ptr, &fractal->bpp, &fractal->line_len, &fractal->endian);
//	fractal.x_c = -2.f + fractal.zoom * i;
//	fractal.y_c = -2.f + fractal.zoom * j;
//	st.x_step = 4.f / (float)st.win_w;
//	st.x_step = 4.f / (float)st.win_w;
}

int		main(int argc, char **argv)
{
	t_fractal fractal;

	init(&fractal);
//	mlx_hook(fractal.win, 2, 0, &key_events, &fractal);
	mlx_hook(fractal.win, 4, 0, &mouse_events, &fractal);
	mlx_loop_hook(fractal.mlx, &render, &fractal);
	mlx_loop(fractal.mlx);
	return 0;
}
