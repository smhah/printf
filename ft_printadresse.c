/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadresse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:10:40 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 10:10:43 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countadresse(size_t n)
{
	int i;
	int e;

	i = 0;
	e = 0;
	while (n > 0)
	{
		e = n % 16;
		n = n / 16;
		if (e < 10)
			i++;
		else
			i++;
	}
	return (i);
}

char	*ft_printadresse(size_t n)
{
	char	*temp;
	char	*rev;
	int		e;
	int		i;

	if (n == 0 && (rev = ft_strdup("0")))
		return (rev);
	i = 0;
	temp = malloc(sizeof(char) * (1 + ft_countadresse(n)));
	while (n > 0)
	{
		e = n % 16;
		n = n / 16;
		if (e < 10)
			temp[i++] = e + 48;
		else
			temp[i++] = e + 55;
	}
	temp[i] = '\0';
	e = 0;
	rev = ft_reverse(temp);
	return (rev);
}
