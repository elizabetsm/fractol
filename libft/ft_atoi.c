/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:34:10 by efleta            #+#    #+#             */
/*   Updated: 2019/09/19 23:25:56 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	i;
	int				n;

	n = 1;
	i = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
				*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		n = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (i < 0 && n == -1)
			return (0);
		if (i < 0 && n == 1)
			return (-1);
		i = i * 10 + (*str - '0');
		++str;
	}
	if (i > 9223372036854775807)
		return (n > 0 ? -1 : 0);
	return (i * n);
}