/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:13:37 by smhah             #+#    #+#             */
/*   Updated: 2019/10/22 21:35:44 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;
	int		i;

	if (lst)
	{
		i = ft_lstsize(lst);
		temp = lst;
		while (i)
		{
			f(temp->content);
			temp = temp->next;
			i--;
		}
	}
}
