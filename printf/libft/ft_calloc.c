/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:11:09 by smhah             #+#    #+#             */
/*   Updated: 2019/10/20 21:36:41 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	int		i;

	i = 0;
	if (!(buffer = (void *)malloc(size * count)))
		return (0);
	if (buffer)
	{
		ft_bzero(buffer, size * count);
		return (buffer);
	}
	return (0);
}
