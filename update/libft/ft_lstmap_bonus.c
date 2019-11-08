/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:37:09 by smhah             #+#    #+#             */
/*   Updated: 2019/10/23 22:58:03 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_rlstclear(t_list **lst, void (*del)(void*))
{
	t_list *t;
	t_list *temp;

	if (*lst)
	{
		t = *lst;
		while (t != NULL)
		{
			temp = t->next;
			del(t->content);
			free(t);
			t = temp;
		}
		*lst = NULL;
		return (0);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*rs;
	t_list	*node;

	node = NULL;
	if (!f || !del)
		return (NULL);
	while (lst != NULL)
	{
		if (node == NULL)
		{
			if (!(rs = ft_lstnew(f(lst->content))) && !f(lst->content))
				return (NULL);
			node = rs;
		}
		else
		{
			if (!(node->next = ft_lstnew(f(lst->content))))
				return (ft_rlstclear(&rs, del));
			node = node->next;
		}
		lst = lst->next;
	}
	return (rs);
}
