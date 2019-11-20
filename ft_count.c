/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:48:18 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 13:48:20 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countetoiles(char *arg)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (arg[i])
	{
		if (arg[i++] == '%')
		{
			while (arg[i] != '%' && arg[i] && (ft_isparam(arg[i], 0) < 0))
			{
				if (arg[i++] == '*')
					c++;
			}
		}
	}
	return (c);
}

int		ft_count(char *arg)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (arg[i])
	{
		if (arg[i++] == '%')
		{
			c++;
			if (arg[i] == '%')
				i++;
			while (arg[i] != '%' && arg[i])
				i++;
		}
	}
	return (c);
}

int		ft_fastetoiles(char *indices)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (indices[i])
	{
		while (indices[i] == '9' && indices[i])
			i++;
		if (indices[i++] == '\0')
			break ;
		c++;
	}
	return (c);
}

int		ft_fastcount(char *indices)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (indices[i])
	{
		while (indices[i] == '9' && indices[i++])
			c++;
		if (indices[i++] == '\0')
			break ;
	}
	return (c);
}

char	*ft_indices(char **str)
{
	int		i;
	int		j;
	char	*indices;

	i = 0;
	j = 0;
	indices = malloc(sizeof(int ) * (ft_count(*str) + ft_countetoiles(*str)));
	while ((*str)[i] != '\0')
	{
		if ((*str)[i++] == '%')
		{
			while ((*str)[i])
			{
				if (((ft_isparam((*str)[i], 0)) >= 0)
						&& (indices[j++] = ft_isparam((*str)[i], 0)
							+ 48) && (i = i + 1) > 0)
					break ;
				else if ((*str)[i] == '*' && (i = i + 1) > 0)
					indices[j++] = 9 + 48;
			}
		}
	}
	indices[j] = '\0';
	return (indices);
}
