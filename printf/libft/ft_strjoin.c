/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:06:59 by smhah             #+#    #+#             */
/*   Updated: 2019/10/20 17:10:52 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*s;

	if (s1 && s2)
		i = ft_strlen((char *)s1);
	else
		return (0);
	j = ft_strlen((char *)s2);
	if (!(s = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
