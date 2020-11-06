/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:32:29 by efleta            #+#    #+#             */
/*   Updated: 2019/09/19 19:36:37 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		a[i] = f(s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}
