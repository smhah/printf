/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:10:27 by smhah             #+#    #+#             */
/*   Updated: 2019/10/20 20:24:49 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *to, const void *from, int c, size_t n)
{
	unsigned int	i;
	char			*pto;
	const char		*pfrom;

	i = 0;
	pto = (char *)to;
	pfrom = (char *)from;
	while (i < n)
	{
		pto[i] = pfrom[i];
		if (pfrom[i] == (char)c)
			return (to + i + 1);
		i++;
	}
	return (0);
}
