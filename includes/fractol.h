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

#include "libft.h"
#include <mlx.h>
#include <stdio.h>
#include <libcl.h>

typedef struct	s_fractal
{
	void	*mlx;
	void	*win;
	int		win_h;
	int		win_w;

	int		depth;

	float	left_b;
	float	right_b;
	float	top_b;
	float	bot_b;
	float	radius;

	t_cl	*cl;

	char	*img_ptr;
	int		*img_int;
	int		bpp;
	int		line_len;
	int		endian;
}				t_fractal;

int		render(t_fractal *fractal);
int		kp(int key, void *l);
int		close_my(void *lst);
int		mm(int event, void *l);



#endif