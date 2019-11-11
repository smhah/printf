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

char **ft_modify(char **tab, char *etoiles)
{
        
}
char *ft_activeflag(char **flags, char **tab, char **etoiles)
{
        int i;
        int j;
        char *str;

        ft_checkerrors(flags);
        i = strlen(flags) - 1;
        j = 0;
        str = malloc(strlen(flags) + 1);
        while(i >= 0)
        {
                if(ft_isdigit(etoiles[i][0]))
                        ft_modify(flags, etoiles[i]);
                if(ft_isdigit(flags[i]))
                        str[j++] = flags[i];
                if (ft_isflag2(flags[i]))
                        ft_active(flags, tab[i], i, str);
                i++;
        }
}

int main()
{
        printf("\n%m%dheho", 3);
}