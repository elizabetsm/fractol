/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 00:11:38 by efleta            #+#    #+#             */
/*   Updated: 2019/09/20 19:32:20 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*a;
	int		b;

	if (!s)
		return (NULL);
	b = 0;
	j = ft_strlen(s) - 1;
	i = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (j >= i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	a = (char *)malloc(sizeof(char) * (j - i + 2));
	if (a == NULL)
		return (NULL);
	while (i <= j)
	{
		a[b++] = s[i++];
	}
	a[b] = '\0';
	return (a);
}
