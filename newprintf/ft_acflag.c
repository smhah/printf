#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_printf.h"

int ft_checkfirst(char *flags, int i)
{
        if(flags[i-1] == '0' && i == 1)
                return (1);
        while (flags[i] == '-')
                i--;
        if (i == -1)
                return (1);
        return (0);
}

char	*ft_tabjoin(char **s1, char **s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*s;

	if (*s1 && *s2)
		i = ft_strlen(*s1);
	else
		return (0);
	j = ft_strlen(*s2);
	if (!(s = malloc(sizeof(char) * (i + j + 1))))
		return (0);
	i = 0;
	j = 0;
	while ((*s1)[i] != '\0')
	{
		s[i] = (*s1)[i];
		i++;
	}
	while ((*s2)[j] != '\0')
		s[i++] = (*s2)[j++];
	s[i] = '\0';
        free(*s1);
        free(*s2);
	return (s);
}

char	*ft_tabjoin2(char *s1, char **s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*s;

	if (s1 && *s2)
		i = ft_strlen(s1);
	else
		return (0);
	j = ft_strlen(*s2);
	if (!(s = malloc(sizeof(char) * (i + j + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	while ((*s2)[j] != '\0')
		s[i++] = (*s2)[j++];
	s[i] = '\0';
        free(*s2);
	return (s);
}

void ft_delfirst(char **tab)
{
        char *str;
        int i;
        int j;

        str = malloc(ft_strlen(*tab));
        i = 0;
        j = 0;
        while ((*tab)[i++])
                str[j++] = (*tab)[i];
        str[j] = '\0';
        free(*tab);
        *tab = str;
        //free(str);
}

void    ft_flagmoin(char **tab, char **add, int indice, int len)
{
        *add = memset(*add,' ',len);
        (*add)[len] = '\0';
        *tab = ft_tabjoin(tab, add);
        if (indice == 2)
                *tab = ft_tabjoin2("-", tab);
}

int     ft_isnum(char **tab)
{
        int i;

        i = 0;
        while ((*tab)[i])
        {
                if(!ft_isdigit((*tab)[i]))
                        return (0);
                i++;
        }
        return (1);
}

void    ft_active (char *flags, char **tab , int i, char **strnum)
{
        //char *str;
        char *add;
        int indice;
        //char *temp;
        int len;
        
        indice = -1;
        if (ft_atoi(&flags[i]) == 0 && ft_atoi(*tab) == 0 && ft_isnum(tab))
                (*tab)[0] = '\0';
        len = atoi((*strnum)) - ft_strlen(*tab);
        if (len < 0)
        {
                free((*strnum));
                *strnum = NULL;
		return ;
        }
        add = malloc(sizeof(char) * len);
        if (ft_checkfirst(flags, i))
                indice = 1;
        if (atoi(*tab) < 0)
        {
                if (flags[i] == '.')
                        len++;
                ft_delfirst(tab);
                indice = 2;
        }
        if(indice > 0 && flags[i] == '-' && (flags[i-1] != '-' || flags[i+1] != '-'))
                ft_flagmoin(tab, &add, indice, len);
        // if(indice > 0 && flags[i] == '-' && (flags[i-1] != '-' || flags[i+1] != '-'))
        // {
        //                 add = memset(add,' ',len);
        //                 add[len] = '\0';
        //                 *tab = ft_tabjoin(tab, &add);
        //                 if (indice == 2)
        //                         *tab = ft_tabjoin2("-", tab);
        // }
        else if (flags[i] == '.')
        {
                add = memset(add,'0',len);
                add[len] = '\0';
                //temp = *tab;
                *tab = ft_tabjoin(&add, tab);
                if (indice == 2)
                        *tab = ft_tabjoin2("-", tab);
        }
         else if (flags[i] == '0')
        {
                //printf("t");
                add = memset(add,'0',len);
                add[len] = '\0';
                //temp = *tab;
                *tab = ft_tabjoin(&add, tab);
                if (indice == 2)
                        *tab = ft_tabjoin2("-", tab);
        }
        else if (ft_isdigit(flags[i]))
        {
                add = memset(add,' ',len);
                add[len] = '\0';
                if (indice == 2)
                        *tab = ft_tabjoin2("-", tab);
                        //You should free tab;;
                *tab = ft_tabjoin(&add, tab);
        }
        else if (indice == 2)
                *tab = ft_tabjoin2("-", tab);
        free((*strnum));
        *strnum = NULL;
}

int ft_isflag2(char a)
{
       if (a == '.' || a == '-' || a == '+' || a == '*')
                return(1);
        return (0);
}

char   *ft_replace(char *flag, char **etoiles, int *e)
{
        char *newflag;
        int i;
        int j;
        int k;

        k = 0;
        j = 0;
        i = 0;
        newflag = malloc(sizeof(char) * (ft_strlen(etoiles[*e]) + ft_strlen(flag) + 1));
        while (flag[i])
        {
                while(flag[i] != '*' && flag[i])
                        newflag[j++] = flag[i++];
                        //strcpy !!
                if(flag[i] == '\0')
                        break;
                if(flag[i++] == '*')
                {
                        j = ft_strcpy(&newflag[j],etoiles[*e], j);
                        *e = *e + 1;
                } 
        }
        newflag[j] = '\0';
        free(flag);
        return (newflag);
}

void    ft_modify(char **flag, char **etoiles)
{
        int i;
        int j;

        j = 0;
        i = 0;
        while(flag[i])
        {
                if(ft_strchr(flag[i], '*'))
                        flag[i] = ft_replace(flag[i], etoiles, &j);
                i++;
        }
        i = 0;
        while(etoiles[i])
        {
                free(etoiles[i++]);
        }
}

int ft_cnd1(int a, int i)
{
        if ((i == 0) && (a = '0'))
                return (0);
        return (1);
}

int ft_cnd2(int a,int b,int i, char *flags)
{
        
        //if ((ft_isflag2(a) && ft_isdigit(b)))
        if (ft_isflag2(a))
        {
                if (a == '-')
                {
                        if (ft_checkfirst(flags, i))
                                return (1);
                        return(-2);
                }
                return (1);
        }
        else if ( i == 0 && b == '0')
        {
                //*flags = '.';
                return (1);
        }
        else if ((i == 0 && ft_isdigit(b)))
                return (1);
        return (0);
}

char    *ft_verse(char **str)
{
    char *rev;
    int i;
    int j;

    if(str[0][0] == '\0')
        printf("T");
    j = 0;
    i = ft_strlen(*str);
    rev = malloc(ft_strlen(*str) + 1);
    while (--i >= 0)
        rev[j++] = (*str)[i];
    rev[j] = '\0';
    free(*str);
    str = NULL;
    return (rev);
}

int  ft_activeflag(char **flags, char **tab)
{
        int i;
        int j;
        char *str;

        str = NULL;
        if (*flags && **flags != '\0')
        {
                i = strlen(*flags) - 1;
                j = 0;
                while(i >= 0)
                {
                        //if is problem add ft_isdigit(flags[e][i])
                        if (str == NULL)
                        {
                                j = 0;
                                str = malloc(ft_strlen(*flags) + 1);
                        }
                        if(ft_isdigit((*flags)[i]))
                                str[j++] = (*flags)[i];
                        if(str && ft_cnd2((*flags)[i], str[j - 1], i,&(*flags)[0]) > 0)
                        {
                                str[j] = '\0';
                                if(str[0])
                                        str = ft_verse(&str);
                                ft_active(*flags, &(*tab), i, &str);
                        }
                        if(str && ft_cnd2((*flags)[i], str[j-1], i, &(*flags)[0]) < 0)
                         {
                                free(str);
                                str = NULL;
                         }
                        i--;
                }
        }
        printf("%s", *tab);
        return (ft_strlen(*tab));
}

// int main()
// {
//         printf("\n%m%dheho", 3);
// }
