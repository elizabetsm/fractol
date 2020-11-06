/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:34:18 by efleta            #+#    #+#             */
/*   Updated: 2019/09/17 18:41:51 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *a, int c)
{
	int		i;
	char	*b;

	b = (char *)a;
	i = (int)ft_strlen(b);
	while (i >= 0)
	{
		if (b[i] == (char)c)
			return (&b[i]);
		i--;
	}
	return (NULL);
}
