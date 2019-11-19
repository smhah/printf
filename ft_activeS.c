#include "ft_printf.h"
#include "libft/libft.h"

char *ft_trim(char **tab, char **strnum)
{
        char *str;
        int j;
        int i;

        i = 0;
        j = ft_atoi((const char *)*strnum);
        str = malloc(j);
        while(j)
        {
                str[i] = (*tab)[i];
                i++;
                j--;
        }
        str[i] = '\0';
        free(*tab);
        return (str); 
}

void    ft_activeS(char *flags, char **tab , int i, char **strnum)
{
        //char *str;
        char *add;
        int indice;
        //char *temp;
        int len;
        
        indice = -1;
        len = atoi((*strnum)) - ft_strlen(*tab);
        if (len < 0 && flags[i] != '.')
        {
                free((*strnum));
                *strnum = NULL;
		return ;
        }
        add = malloc(sizeof(char) * len);
        if (ft_checkfirst(flags, i))
                indice = 1;
        if(indice > 0 && flags[i] == '-' && (flags[i-1] != '-' || flags[i+1] != '-'))
        {
                        add = memset(add,' ',len);
                        add[len] = '\0';
                        *tab = ft_tabjoin(tab, &add);
        }
        else if (flags[i] == '.' && flags[i+1] != '-')
                *tab = ft_trim(tab,strnum);
        else if (ft_isdigit(flags[i]))
        {
                add = memset(add,' ',len);
                add[len] = '\0';
                *tab = ft_tabjoin(&add, tab);
        }
        free((*strnum));
        *strnum = NULL;
}

int ft_cnd2s(int a,int b,int i, char *flags)
{
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
        else if ((i == 0 && ft_isdigit(b)))
                return (1);
        return (0);
}

int ft_activeflagS(char **flags, char **tab)
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
                        if(str && ft_cnd2s((*flags)[i], str[j - 1], i,&(*flags)[0]) > 0)
                        {
                                str[j] = '\0';
                                if(str[0])
                                        str = ft_verse(&str);
                                
                                ft_activeS(*flags, &(*tab), i, &str);
                        }
                        if(str && ft_cnd2s((*flags)[i], str[j-1], i, &(*flags)[0]) < 0)
                         {
                                free(str);
                                str = NULL;
                         }
                        i--;
                }
        }
        printf("%s", *tab);
        return(ft_strlen(*tab));
}