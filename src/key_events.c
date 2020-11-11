/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 08:52:37 by efleta            #+#    #+#             */
/*   Updated: 2020/11/08 08:52:39 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	key_events1(int key, t_fractal *fractal)
{
	if (key == 124)
	{
		fractal->left_b -= 0.01f;
		fractal->right_b -= 0.01f;
	}
	else if (key == 123)
	{
		fractal->left_b += 0.01f;
		fractal->right_b += 0.01f;
	}
	else if (key == 49)
		setup_default(fractal);
	else if (key == 47)
	{
		fractal->color += 5934;
	}
}

int		key_events(int key, t_fractal *fractal)
{
	if (key == 53)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(0);
	}
	else if (key == 125)
	{
		fractal->bot_b += 0.01f;
		fractal->top_b += 0.01f;
	}
	else if (key == 126)
	{
		fractal->bot_b -= 0.01f;
		fractal->top_b -= 0.01f;
	}
	else
		key_events1(key, fractal);
	render(fractal);
	return (0);
}
