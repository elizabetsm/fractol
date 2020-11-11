/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 08:47:49 by efleta            #+#    #+#             */
/*   Updated: 2020/11/08 08:47:52 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_args(char *arg, t_fractal *fractal)
{
	if (arg[0] == 'm' && arg[1] == '\0')
		fractal->fractol = 'm';
	else if (arg[0] == 'j' && arg[1] == '\0')
		fractal->fractol = 'j';
	else if (arg[0] == 's' && arg[1] == '\0')
		fractal->fractol = 's';
	else
	{
		throw_usage();
		exit(-1);
	}
}

void	throw_usage(void)
{
	ft_putstr("usage : ./fractol [m, j, s]\n");
}

void	print_control(void)
{
	ft_putstr("space       - Reset to default\n");
	ft_putstr("mouse left  - Change (ON/OF)\n");
	ft_putstr("mouse move  - Change coefficient\n");
	ft_putstr(" >          - Change color\n");
	ft_putstr("ESC         - Exit\n");
}

void	cl_setup_program(t_cl **cl)
{
	*cl = cl_setup((char *[]){"src/mandelbrot.cl", NULL},
				(char *[]){"mandelbrot", NULL}, NULL);
	cl_setup((char *[]){"src/burning_ship.cl", NULL},
		(char *[]){"burning_ship", NULL}, *cl);
	cl_setup((char *[]){"src/julia.cl", NULL},
			(char *[]){"julia", NULL}, *cl);
}

void	setup_default(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win_w = 1600;
	fractal->win_h = 1600;
	fractal->depth = 2000;
	fractal->radius = 4.f;
	fractal->left_b = -2.f;
	fractal->right_b = 2.f;
	fractal->bot_b = -2.f;
	fractal->top_b = 2.f;
	fractal->color = 236764;
	fractal->koef_x = 0;
	fractal->koef_y = 0;
	fractal->check_mouse_move = 0;
}
