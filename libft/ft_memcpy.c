/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:41:08 by efleta            #+#    #+#             */
/*   Updated: 2019/09/21 13:35:55 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t		i;
	char		*dd;
	const char	*ss;

	i = 0;
	if ((!destination && !source) && n > 0)
		return (NULL);
	dd = (char *)destination;
	ss = (const char *)source;
	while (i < n)
	{
		dd[i] = ss[i];
		i++;
	}
	return (dd);
}
