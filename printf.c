/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:21:18 by smhah             #+#    #+#             */
/*   Updated: 2019/11/04 22:40:10 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int addingNumbers(int nHowmany, ...)
{
	int		i;
	int		sum;
	va_list numbers;
	int c;

	i = -1;
	sum = 0;
	va_start(numbers, nHowmany);
	while (++i < nHowmany)
	{
		printf("after:%d\n", c);
		c = va_arg(numbers, int);
		printf("befaure:%d\n", c);	
		sum = sum + c;
	}
	va_end(numbers);
	return (sum);
}

void *ft_putstr(char *s)
{
	while (*s)
		write(1, &(*s++),1);
	return (0);
}

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

int main ()
{
	char *str;
	int i;

	str = "x%dxx%dxxxxx%dxxxxii";
	i = ft_countarg(str,"%d");
	printf("numb of arg is : %d", i); 
	//printf("%s\n", strstr("xxxx%dxx","%d"));
	//ft_putstr("xxx%dx");
	//printf("10 + 11 = %d\n", addingNumbers(10,11,2,1,1,1,1,1,1,1,1));
}
