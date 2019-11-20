/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:41:21 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 12:20:02 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isflag2(char a)
{
	if (a == '.' || a == '-' || a == '+' || a == '*')
		return (1);
	return (0);
}

char	*ft_replace(char *flag, char **etoiles, int *e)
{
	char	*newflag;
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 0;
	i = 0;
	newflag = malloc(sizeof(char) *
		(ft_strlen(etoiles[*e]) + ft_strlen(flag) + 1));
	while (flag[i])
	{
		while (flag[i] != '*' && flag[i])
			newflag[j++] = flag[i++];
		if (flag[i] == '\0')
			break ;
		if (flag[i++] == '*')
		{
			j = ft_strcpy(&newflag[j], etoiles[*e], j);
			*e = *e + 1;
		}
	}
	newflag[j] = '\0';
	free(flag);
	return (newflag);
}

void	ft_modify(char **flag, char **etoiles)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (flag[i])
	{
		if (ft_strchr(flag[i], '*'))
			flag[i] = ft_replace(flag[i], etoiles, &j);
		i++;
	}
	i = 0;
	while (etoiles[i])
	{
		free(etoiles[i++]);
	}
}

int		ft_cnd1(int a, int i)
{
	if ((i == 0) && (a = '0'))
		return (0);
	return (1);
}

int		ft_cnd2(int a, int b, int i, char *flags)
{
	if (ft_isflag2(a))
	{
		if (a == '-')
		{
			if (ft_checkfirst(flags, i))
				return (1);
			return (-2);
		}
		return (1);
	}
	else if (i == 0 && b == '0')
		return (1);
	else if ((i == 0 && ft_isdigit(b)))
		return (1);
	return (0);
}
