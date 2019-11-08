/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rang.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:30:20 by smhah             #+#    #+#             */
/*   Updated: 2019/11/07 00:43:43 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char *t;

	t = *a;
	*a = *b;
	*b = t;
}

int		ft_strcmp(char **s1, char **s2)
{
	if (*s1 > *s2)
		return (1);
	else if (*s1 < *s2)
		return (-1);
	else if (*s1 == *s2)
		return (0);
	return (0);
}

char	**ft_rangadrs(char **tab, int e)
{
	int diff;
	int i;
	int j;

	diff = 0;
	i = 0;
	while (i < e)
    {
        j = i + 1;
        while ( j < e)
        {
            diff = ft_strcmp(&tab[i], &tab[j]);
            if (diff > 0)
                ft_swap(&tab[i], &tab[j]);
            j++;
        }
        i++;
	}
	return(tab);
}

char    **ft_rang(char ***xtab, int e)
{
        int i;
        int b;
        int a;
        char **tab;

        tab = malloc(sizeof(char *) * (e + 1));
        a = 0;
        i = 0;
        while (i < e)
        {
            b = 0;
             while(xtab[a][b])
                tab[i++] = xtab[a][b++];
			a++;
        }
        tab[i] = 0;
		tab = ft_rangadrs(tab, e);
        return (tab);
}
