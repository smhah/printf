/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 00:13:36 by smhah             #+#    #+#             */
/*   Updated: 2019/10/20 20:24:48 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t n)
{
	char			*pto;
	const char		*pfrom;

	pto = (char *)to;
	pfrom = (char *)from;
	if (pto == 0 && pfrom == 0)
		return (0);
	if (pto > pfrom)
	{
		while (n >= 1)
		{
			pto[n - 1] = pfrom[n - 1];
			n--;
		}
	}
	else
	{
		while (n--)
			*pto++ = *pfrom++;
	}
	return (to);
}
