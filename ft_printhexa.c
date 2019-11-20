/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:22:26 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 12:26:15 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_counthexa(unsigned int n)
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

void	ft_setup(char **rev)
{
	int i;

	i = 0;
	while ((*rev)[i] != '\0')
	{
		if ((*rev)[i] >= 'A' && (*rev)[i] <= 'Z')
			(*rev)[i] = (*rev)[i] + 32;
		i++;
	}
}

char	*ft_reverse(char *str)
{
	char	*rev;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	rev = malloc(ft_strlen(str) + 1);
	while (--i >= 0)
		rev[j++] = str[i];
	rev[j] = '\0';
	free(str);
	ft_setup(&rev);
	return (rev);
}

char	*ft_printhexa(unsigned int n)
{
	char	*temp;
	char	*rev;
	int		e;
	int		i;

	if (n == 0 && (rev = ft_strdup("0")))
		return (rev);
	i = 0;
	temp = malloc(sizeof(char) * (1 + ft_counthexa(n)));
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
