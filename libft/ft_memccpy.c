/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:52:21 by efleta            #+#    #+#             */
/*   Updated: 2019/09/21 13:36:00 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char	*dd;
	unsigned char	*ss;
	size_t			i;

	dd = (unsigned char *)d;
	ss = (unsigned char *)s;
	i = 0;
	if (dd == NULL && ss == NULL)
		return (NULL);
	while (i < n)
	{
		dd[i] = ss[i];
		if (ss[i] == (unsigned char)c)
			return (dd + i + 1);
		i++;
	}
	return (NULL);
}
