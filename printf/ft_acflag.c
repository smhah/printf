#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "printf.h"

int ft_checkfirst(char *flags, int i)
{
        while (flags[i] == '-')
                i--;
        if (i == -1)
                return (1);
        return (0);
}

void    ft_active (char *flags, char **tab , int i, char **strnum)
{
        //char *str;
        char *add;
        int indice;
        //char *temp;
        int len;

        if (flags[i + 1] == '\0' && atoi(*tab) == 0)
                (*tab)[0] = '\0';
        indice = 0;
        len = atoi((*strnum)) - ft_strlen(*tab);
        if (len < 0)
        {
                free((*strnum));
                *strnum = NULL;
		return ;
        }
        add = malloc(sizeof(char) * len);
        if (!ft_checkfirst(flags, i))
                indice = 1;
        if(indice == 0 && flags[i] == '-' && (flags[i-1] != '-' || flags[i+1] != '-'))
        {
                        add = memset(add,' ',len);
                        add[len] = '\0';
                        *tab = ft_strjoin(*tab, add);
                        free(add);
        }
        else if (flags[i] == '.')
        {
                add = memset(add,'0',len);
                add[len] = '\0';
                //temp = *tab;
                *tab = ft_strjoin(add, *tab);
                free(add);
        }
        else if (ft_isdigit(flags[i]))
        {
                add = memset(add,' ',len);
                add[len] = '\0';
                *tab = ft_strjoin(add, *tab);
                free(add);
        }
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
        //free(flag);
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
                (*flags) = '.';
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

void  ft_activeflag(char **flags, char **tab, char **etoiles)
{
        int i;
        int j;
        char *str;
        int e;

        e = 0;
        str = NULL;
        ft_modify(flags, etoiles);
        while (flags[e])
        {
                i = strlen(flags[e]) - 1;
                j = 0;
                while(i >= 0)
                {
                        //if is problem add ft_isdigit(flags[e][i])
                        if (str == NULL)
                        {
                                j = 0;
                                str = malloc(ft_strlen(flags[e]) + 1);
                        }
                        if(ft_isdigit(flags[e][i]))
                                str[j++] = flags[e][i];
                        if(str && ft_cnd2(flags[e][i], str[j - 1], i,&flags[e][0]) > 0)
                        {
                                str[j] = '\0';
                                if(str[0])
                                        str = ft_verse(&str);
                                ft_active(flags[e], &tab[e], i, &str);
                        }
                        if(str && ft_cnd2(flags[e][i], str[j-1], i, &flags[e][0]) < 0)
                        {
                                free(str);
                                str = NULL;
                        }
                        i--;
                }
                e++;
        }
}

// int main()
// {
//         printf("\n%m%dheho", 3);
// }
