/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 23:35:01 by efleta            #+#    #+#             */
/*   Updated: 2019/09/24 12:19:32 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst1;

	lst1 = lst;
	if (!lst1 || !f)
		return (NULL);
	if (lst != NULL)
	{
		lst1 = f(lst);
		lst1->next = ft_lstmap(lst->next, f);
	}
	return (lst1);
}
