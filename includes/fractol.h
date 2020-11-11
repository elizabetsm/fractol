/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:00:41 by efleta            #+#    #+#             */
/*   Updated: 2020/11/02 22:00:43 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include "../libcl/include/libcl.h"

typedef struct	s_fractal
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;

	int			depth;

	float		left_b;
	float		right_b;
	float		top_b;
	float		bot_b;
	float		radius;

	t_cl		*cl;

	char		*img_ptr;
	int			*img_int;
	int			bpp;
	int			line_len;
	int			endian;

	int			color;
	char		fractol;

	float		koef_x;
	float		koef_y;
	int			check_mouse_move;

	float		step_x;
	float		step_y;
}				t_fractal;

void			render(t_fractal *fractal);
void			check_args(char *arg, t_fractal *fractal);
void			throw_usage(void);
void			cl_setup_program(t_cl **cl);
int				key_events(int key, t_fractal *fractal);
int				mouse_events(int event, int x, int y, t_fractal *fractal);
int				mouse_move(int x, int y, t_fractal *fractal);
void			setup_default(t_fractal *fractal);
void			print_control(void);
int				set_up_kernel_mandelbrot(t_fractal *fractal, int err,
								cl_mem mem_img, cl_kernel *kernel);
int				set_up_kernel_julia_burning_ship(t_fractal *fractal, int err,
											cl_mem mem_img, cl_kernel *kernel);

#endif
