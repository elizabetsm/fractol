/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:28:55 by efleta            #+#    #+#             */
/*   Updated: 2019/09/18 16:14:00 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hh, const char *n)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!hh[i] & !n[i])
		return ((char *)hh);
	if (!hh[i])
		return (NULL);
	if (!n[i])
		return ((char *)hh);
	while (hh[i] != '\0')
	{
		if (hh[i] == n[0])
		{
			while (n[j] != '\0' && hh[i + j] == n[j])
				j++;
			if (n[j] == '\0')
				return ((char *)&hh[i]);
		}
		i++;
	}
	return (NULL);
}
