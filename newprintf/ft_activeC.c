#include "ft_printf.h"

void    ft_activeC(char *flags, char **tab , int i, char **strnum)
{
        char *add;
        int indice;
        int len;
        
        indice = -1;
        len = atoi((*strnum)) - 1;
        if (len < 0)
        {
                free((*strnum));
                *strnum = NULL;
		return ;
        }
        // if (**tab == '\0')
        // {
        //     len--;
        // }
        add = malloc(sizeof(char) * len);
        if (ft_checkfirst(flags, i))
                indice = 1;
        if(indice > 0 && flags[i] == '-' && (flags[i-1] != '-' || flags[i+1] != '-'))
        {
                        add = memset(add,' ',len);
                        add[len] = '\0';
                        *tab = ft_tabjoin(tab, &add);
        }
        else if (ft_isdigit(flags[i]))
        {
                add = memset(add,' ',len);
                add[len] = '\0';
                *tab = ft_tabjoin(&add, tab);
        }
        free((*strnum));
        *strnum = NULL;
}

int  ft_activeflagC(char **flags, char **tab)
{
        int i;
        int j;
        char *str;
        int e;

        e = 0;
        str = NULL;
        if(flags[e][0] != '\0')
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
                        if(str && ft_cnd2s(flags[e][i], str[j - 1], i,&flags[e][0]) > 0)
                        {
                                str[j] = '\0';
                                if(str[0])
                                        str = ft_verse(&str);
                                
                                ft_activeC(flags[e], &tab[e], i, &str);
                        }
                        if(str && ft_cnd2s(flags[e][i], str[j-1], i, &flags[e][0]) < 0)
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