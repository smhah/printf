/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:32:56 by smhah             #+#    #+#             */
/*   Updated: 2019/10/20 20:27:55 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		leng;

	leng = ft_strlen((char *)src);
	i = 0;
	if (size == 0)
		return (leng);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = (char)src[i];
		i++;
	}
	dst[i] = '\0';
	return (leng);
}
