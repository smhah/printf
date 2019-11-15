/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:21:31 by smhah             #+#    #+#             */
/*   Updated: 2019/10/22 21:36:29 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
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
	}
}
