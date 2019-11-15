/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:48:56 by smhah             #+#    #+#             */
/*   Updated: 2019/10/14 00:55:40 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	unsigned int	leng;
	unsigned int	i;
	char			*dup;

	leng = ft_strlen((char *)str);
	dup = (char *)malloc((sizeof(char) * (leng + 1)));
	if (dup == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = str[i];
	return (dup);
}
