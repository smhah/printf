/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 09:52:49 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 09:56:56 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_i;
int g_k;
int g_j;
int g_g;

void	ft_delzero(char **str)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = malloc(ft_strlen(*str));
	while ((*str)[++i])
	{
		newstr[j++] = (*str)[i];
	}
	newstr[j] = '\0';
	free(*str);
	*str = newstr;
}

void	ft_ignore(char **flags, char *indices)
{
	int i;
	int j;

	i = 0;
	while (flags[i])
	{
		j = 0;
		if (flags[i][j] == '0' && indices[i] != '8')
		{
			while (flags[i][++j])
			{
				if (flags[i][j] == '.')
					ft_delzero(&flags[i]);
			}
		}
		i++;
	}
}

int		ft_printf(const char *arg, ...)
{
	char	*str;
	char	*indices;
	char	**flags;
	va_list n;

	va_start(n, arg);
	str = ft_trimarg((char *)arg);
	indices = ft_indices(&str);
	flags = ft_flag((char *)arg, str);
	ft_ignore(flags, indices);
	return (ft_subprintf(indices, flags, n, &str));
}
