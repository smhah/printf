/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:09:26 by smhah             #+#    #+#             */
/*   Updated: 2019/11/03 21:55:50 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int ft_countarg(char *str, char *needle)
{
	int i;

	i = 0;
	while (str)
	{
		str = strstr(str,needle);
		if (str)
		{
			str = str + 2;
			i++;
		}
	}
	return (i);
}

char *printf(char *arguments, ...)
{

	ft_countarg(arguments,"%d");
	int  addingNumbers(int howmany, ...)
	{
		
	}
}
