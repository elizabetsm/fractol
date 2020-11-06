/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:37:30 by efleta            #+#    #+#             */
/*   Updated: 2019/09/19 19:47:50 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		b;
	char	*a;

	i = 0;
	b = 0;
	if (s == NULL)
		return (NULL);
	while (s[b] != '\0')
		b++;
	b = b + 1;
	a = (char *)malloc(sizeof(char) * b);
	if (a == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		a[i] = f(i, s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}
