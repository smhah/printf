/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:01:36 by smhah             #+#    #+#             */
/*   Updated: 2019/10/28 13:22:25 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char *ft_realloc(char *s);

int get_next_line(int fd, char **line)
{
	static char *p;
	char *stock;
	int j;
	int e;

	*line = ft_strdup("");
	//free(*line);
	//printf("line : %s", *line);
	if(!p)
		p = ft_strdup("");
	if(!(stock = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (0);
	j = 1;
	e = 0;
	
	while(p[0] != '\n' || strchr(line[0],'\n') == 0)
	{
		printf("file has been read");
		j = read(fd, stock, BUFFER_SIZE);
		if (stock[0] == '\0')
		{
			return (0);
		}
		stock[j] = '\0';
		if(!(stock = ft_realloc(stock)))
			return (0);
		line[0] = ft_strdup(stock);
		if (strchr(line[0],'\n'))
		{
			break ;
		}
		line[0] = ft_strjoin(p, line[0]);
		//free(p);
		p = ft_strdup(line[0]);
		//printf("p IN is:{%s}", p);
	}
	line[0] = ft_strjoin(p,line[0]);
	//printf("|pis:%s|", p);
	if (p[0] == '\n')
		line[0] = ft_strjoin(p+1,line[0]);
	while (strchr("\n\0", line[0][e]) == 0)
		e++;
	p = ft_substr(line[0], e, ft_strlen(line[0]) - e);
	printf("{%s}", p);
 	if (line[0][e] != '\n' && j > 0)
	{
		//free(p);
		p = ft_substr(line[0],0,e);
	}
	line[0] = ft_substr(line[0],0,e);
	return (j);
}

int main()
{
	char *line;
	int fd;
	int j;

	j = 1;
	//line = NULL;
	//line = (char **)malloc(sizeof(char *));
	fd = open("text.txt", O_RDONLY);
	//printf("%d\n", fd);
		j = get_next_line(fd, &line);
		printf("result = %d ==>line = %s\n", j, line);
		j = get_next_line(fd, &line);
		printf("result = %d ==>line = %s\n", j, line);
		j = get_next_line(fd, &line);
		printf("result = %d ==>line = %s\n", j, line);
		j = get_next_line(fd, &line);
		printf("result = %d ==>line = %s\n", j, line);
		/* 
		j = get_next_line(fd, &line);
		printf("result = %d ==>line = %s\n", j, line);
		j = get_next_line(fd, &line);
		printf("result = %d ==>line = %s\n", j, line);
		
	//printf("%s", *line);
	*/
}