/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:05:52 by efleta            #+#    #+#             */
/*   Updated: 2019/09/24 15:12:53 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*allclear(char **a)
{
	if (a)
	{
		free(*a);
		*a = NULL;
	}
	return (NULL);
}

static int		wcount(const char *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] != c && (s[k + 1] == c || s[k + 1] == '\0'))
			i++;
		k++;
	}
	return (i);
}

static int		scount(const char *s, int k, int c)
{
	int	i;

	i = 0;
	while (s[k] != c && s[k])
	{
		k++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**a;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	if (!(a = (char **)malloc(sizeof(char *) * (wcount(s, c) + 1))))
		return (NULL);
	while (i < wcount(s, c))
	{
		j = 0;
		while (s[k] == c && s[k])
			k++;
		if (!(a[i] = (char *)malloc(sizeof(char) * (scount(s, k, c) + 1))))
			return (allclear(a));
		while (s[k] != c && s[k])
			a[i][j++] = s[k++];
		a[i][j] = '\0';
		i++;
	}
	a[i] = NULL;
	return (a);
}
