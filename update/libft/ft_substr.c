/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:03:40 by smhah             #+#    #+#             */
/*   Updated: 2019/10/21 04:57:37 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*buf;
	size_t		i;

	i = 0;
	if (s)
	{
		if (!(buf = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
	}
	else
		return (0);
	while ((i < len) && (start + i < ft_strlen(s)))
	{
		buf[i] = s[start + i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
