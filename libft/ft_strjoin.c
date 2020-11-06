/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:58:28 by efleta            #+#    #+#             */
/*   Updated: 2019/09/19 23:55:43 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char **s1, char **s2, int f, int s)
{
	char	*result;
	char	*start;
	char *tmp;

	if (!*s1 && !*s2)
		return (NULL);
	result = ft_strnew((*s1 ? ft_strlen(*s1) : 0) + (*s2 ? ft_strlen(*s2) : 0));
	if ((start = result))
	{
		if ((tmp = *s1))
			while (*tmp)
				*result++ = *tmp++;
		if ((tmp = *s2))
			while (*tmp)
				*result++ = *tmp++;
		*result = '\0';
	}
	if (f)
		ft_strdel(s1);
	if (s)
		ft_strdel(s2);
	return (start);
}
