/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:40:22 by efleta            #+#    #+#             */
/*   Updated: 2019/09/19 21:57:08 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*a;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	a = (char *)malloc(sizeof(char) * len + 1);
	if (a == NULL)
		return (NULL);
	while (i < len)
	{
		a[i] = s[i + start];
		i++;
	}
	a[i] = '\0';
	return (a);
}
