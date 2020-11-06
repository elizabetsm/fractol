/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:43:38 by efleta            #+#    #+#             */
/*   Updated: 2019/09/17 20:55:03 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		a;
	char	*dest;
	char	*ssrc;

	i = 0;
	a = 0;
	ssrc = (char *)src;
	while (*src)
	{
		src++;
		i++;
	}
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	while (ssrc[a])
	{
		dest[a] = ssrc[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
