/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 08:52:53 by efleta            #+#    #+#             */
/*   Updated: 2020/11/08 08:52:54 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_move(int x, int y, t_fractal *fractal)
{
	if (fractal->check_mouse_move == 1)
	{
		fractal->koef_x = -((float)(x) - ((float)fractal->win_w / 2))
				/ ((float)fractal->win_w / 2);
		fractal->koef_y = ((float)(y) - ((float)fractal->win_h / 2))
				/ ((float)fractal->win_h / 2);
		render(fractal);
	}
	return (0);
}

void	mouse_events1(int event, int x, int y, t_fractal *fractal)
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
		fractal->left_b = fractal->left_b + comp_x / 8;
		fractal->right_b = fractal->right_b - (dx - comp_x) / 8;
		fractal->top_b = fractal->top_b - comp_y / 8;
		fractal->bot_b = fractal->bot_b + (dy - comp_y) / 8;
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
}

int		mouse_events(int event, int x, int y, t_fractal *fractal)
{
	if (event == 1)
	{
		if (fractal->check_mouse_move == 0)
			fractal->check_mouse_move = 1;
		else
			fractal->check_mouse_move = 0;
	}
	else
		mouse_events1(event, x, y, fractal);
	render(fractal);
	return (0);
}
