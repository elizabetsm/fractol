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

void	cl_err(int err, t_fractal *fractal, cl_kernel *kernel,
			size_t global_size)
{
	if (err != 0)
		ft_putstr("set kernel arg - error\n");
	err = clEnqueueNDRangeKernel(*fractal->cl->queue, *kernel, 1, NULL,
					&global_size, NULL, 0, NULL, NULL);
	if (err != 0)
		ft_putstr("NDR - error\n");
}

void	set_up_by_name(t_fractal *fractal, cl_kernel **kernel, int err,
					cl_mem mem_img)
{
	if (fractal->fractol == 'm')
	{
		*kernel = cl_get_kernel_by_name(fractal->cl, "mandelbrot");
		err = set_up_kernel_mandelbrot(fractal, err, mem_img, *kernel);
	}
	else if (fractal->fractol == 's')
	{
		*kernel = cl_get_kernel_by_name(fractal->cl, "burning_ship");
		err = set_up_kernel_julia_burning_ship(fractal, err, mem_img, *kernel);
	}
	else if (fractal->fractol == 'j')
	{
		*kernel = cl_get_kernel_by_name(fractal->cl, "julia");
		err = set_up_kernel_julia_burning_ship(fractal, err, mem_img, *kernel);
	}
}

void	render(t_fractal *fractal)
{
	int			err;
	cl_mem		mem_img;
	cl_kernel	*kernel;
	size_t		global_size;

	kernel = NULL;
	mem_img = clCreateBuffer(*fractal->cl->context, CL_MEM_READ_WRITE,
						fractal->win_w * fractal->win_h * sizeof(int),
						NULL, &err);
	if (err != 0)
		ft_putstr("create buffer - error\n");
	global_size = fractal->win_w * fractal->win_h;
	set_up_by_name(fractal, &kernel, err, mem_img);
	cl_err(err, fractal, kernel, global_size);
	err = clEnqueueReadBuffer(*fractal->cl->queue, mem_img, CL_TRUE, 0,
				fractal->win_w * fractal->win_h * sizeof(int),
					fractal->img_int, 0, NULL, NULL);
	if (err != 0)
		ft_putstr("read buffer - error\n");
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img_ptr, 0,
					0);
}

void	init(t_fractal *fractal)
{
	cl_setup_program(&fractal->cl);
	setup_default(fractal);
	fractal->win = mlx_new_window(fractal->mlx, fractal->win_w, fractal->win_h,
						"fract’ol");
	fractal->img_ptr = mlx_new_image(fractal->mlx, fractal->win_w,
							fractal->win_h);
	fractal->img_int = (int *)mlx_get_data_addr(fractal->img_ptr, &fractal->bpp,
										&fractal->line_len, &fractal->endian);
}

int		main(int argc, char **argv)
{
	t_fractal fractal;

	if (argc == 2)
	{
		print_control();
		check_args(argv[1], &fractal);
		init(&fractal);
		mlx_hook(fractal.win, 2, 0, &key_events, &fractal);
		mlx_hook(fractal.win, 4, 0, &mouse_events, &fractal);
		mlx_hook(fractal.win, 6, 0, &mouse_move, &fractal);
		render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
		throw_usage();
	return (0);
}
