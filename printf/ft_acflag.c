#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "printf.h"

int ft_checkdouble(char **flags, int i)
{
        while(i > 0)
        {
                if (flags[i] == '.' || flags[i] == '*' || flags[i] == '-')
                        return (0);
        }
        return(1);
}

int ft_checkfirst(char **flags,int i)
{
        while(flags[i] == '-')
                i++;
        if (i == 0)
                return (1);
        return (0);
}

char *ft_active (char *flags, char *num , int i, char *strnum)
{
        char *str;
        char *add = malloc(atoi(num));

        if( flags[i] == '-')
        {
                if (ft_checkfirst(flags, i))
                {
                        add = memset(add,' ',atoi(strnum) - strlen(num));
                        str = ft_strjoin(num, add);
                        free(add);
                        free(num);
                }
                else
                {
                        str = ft_strdup(num);
                        free(num);
                        return (str);
                }
        }

        // if (flags[i] == '.')

        // if (flags[i] == '%')
        // {
        //         add = memset(add,' ',atoi(strnum) - strlen(num));
        //         str = ft_strjoin(add, num);
        //         free(add);
        //         free(num);
        // }
}

int ft_isflag2(char a)
{
       if (a == '.' || a == '-' || a == ' ' || a == '+' || a == '*')
                return(1);
        return (0);
}

int ft_checkerrors(char **flags)
{
        int i;
        char *checkflags;
        int j;

        i = 0;
        j = 0;
        while(flags[i])
        {
                if(ft_checkdouble(flags[i]))
                        return (0);
                checkflags = ft_strdup(flags[i]);
                checkflags[j] = flags[i][j++];
        }
}

char** ft_replace(char *flag, char **etoiles, int *e)
{
        char *newflag;
        int i;
        int j;
        int k;

        k = 0;
        j = 0;
        i = 0;
        newflag = malloc(sizeof(char) * ft_strlen(etoiles) + ft_strlen(flag) + 1);
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
                j++;
        }
}

char *ft_activeflag(char **flags, char **tab, char **etoiles)
{
        int i;
        int j;
        char *str;
        int k;
        int e;

        e = 0;
        ft_modify(flags, etoiles);
        while (flags[e])
        {
                ft_checkerrors(flags[e]);
                i = strlen(flags[e] - 1);
                j = 0;
                while(i >= 0)
                {
                        k = 0;
                        if(ft_isdigit(flags[e][k]))
                                str[j++] = flags[e][k];
                        if (ft_isflag2(flags[e][k]))
                                ft_active(flags[e], tab[e], i, str);
                        i--;
                }
                e++;
        }
}

// int main()
// {
//         printf("\n%m%dheho", 3);
// }