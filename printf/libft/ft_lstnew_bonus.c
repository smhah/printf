/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:12:57 by smhah             #+#    #+#             */
/*   Updated: 2019/10/21 16:58:09 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *node;

	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}
