/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:20:24 by efleta            #+#    #+#             */
/*   Updated: 2019/09/20 21:18:27 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*t;

	if (!(t = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		t->content = NULL;
		t->content_size = 0;
	}
	else
	{
		if (!(t->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(t->content, (void *)content, content_size);
		t->content_size = content_size;
	}
	t->next = NULL;
	return (t);
}
