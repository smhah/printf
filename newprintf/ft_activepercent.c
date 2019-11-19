#include "ft_printf.h"

void    ft_activepercent(char *flags, char **tab , int i, char **strnum)
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
        // else if (flags[i] == '.')
        // {
        //         add = memset(add,'0',len);
        //         add[len] = '\0';
        //         //temp = *tab;
        //         *tab = ft_tabjoin(&add, tab);
        //         if (indice == 2)
        //                 *tab = ft_tabjoin2("-", tab);
        // }
         else if (flags[i] == '0')
        {
                //printf("t");
                add = memset(add,'0',len);
                add[len] = '\0';
                //temp = *tab;
                *tab = ft_tabjoin(&add, tab);
        }
        else if (ft_isdigit(flags[i]))
        {
                add = memset(add,' ',len);
                add[len] = '\0';
                        //You should free tab;;
                *tab = ft_tabjoin(&add, tab);
        }
        free((*strnum));
        *strnum = NULL;
}


int  ft_activeflagpercent(char **flags, char **tab)
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
                                ft_activepercent(*flags, &(*tab), i, &str);
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