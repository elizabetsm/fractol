/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:45:23 by efleta            #+#    #+#             */
/*   Updated: 2019/09/21 13:11:23 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	char	*d;
	size_t	i;

	d = (char *)destination;
	i = 0;
	while (i < n)
	{
		d[i] = c;
		i++;
	}
	return (d);
}
