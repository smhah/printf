/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:02:44 by smhah             #+#    #+#             */
/*   Updated: 2019/10/20 20:25:34 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*pstr;

	i = 0;
	pstr = (char *)str;
	while (i < n)
	{
		if (pstr[i] == (char)c)
			return (pstr + i);
		i++;
	}
	return (0);
}
