/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:33:11 by efleta            #+#    #+#             */
/*   Updated: 2020/11/09 19:33:13 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strhash(const char *str)
{
	int	res;
	int	p;
	int	i;

	res = 0;
	p = 1;
	i = -1;
	while (str[++i])
	{
		res = (res + (str[i] - 'a') * p) % HASH_M;
		p = (p * HASH_P) % HASH_M;
	}
	return (res);
}
