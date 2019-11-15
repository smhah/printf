/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:56:17 by smhah             #+#    #+#             */
/*   Updated: 2019/10/20 20:24:49 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	unsigned int	i;
	char			*pto;
	const char		*pfrom;

	i = 0;
	pto = (char *)to;
	pfrom = (char *)from;
	if (pto == 0 && pfrom == 0)
		return (0);
	while (i < n)
	{
		pto[i] = pfrom[i];
		i++;
	}
	return (to);
}
