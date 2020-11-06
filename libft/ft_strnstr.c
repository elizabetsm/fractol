/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:55:13 by efleta            #+#    #+#             */
/*   Updated: 2019/09/18 16:29:55 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hh, const char *n, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 1;
	if (!hh[i] & !n[i])
		return ((char *)hh);
	if (!hh[i])
		return (NULL);
	if (!n[i])
		return ((char *)hh);
	while (hh[i] != '\0' && i < len)
	{
		if (hh[i] == n[0])
		{
			while (n[j] != '\0' && hh[i + j] == n[j] && (i + j) < len)
				j++;
			if (n[j] == '\0')
				return ((char *)&hh[i]);
		}
		i++;
	}
	return (NULL);
}
