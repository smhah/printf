#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void    ft_swap(char **a, char **b)
{
    char *t;

    t = *a;
    *a = *b;
    *b = t;
}

int        ft_strcmp(char **s1, char **s2)
{
    if (*s1 > *s2)
        return (1);
    else if (*s1 < *s2)
        return (-1);
    else if (*s1 == *s2)
        return (0);
    return (0);
}

char    **ft_rang(char ***xtab, int e)
{
    int i;
    int diff;
    int b;
    int a;
    char **tab;

    tab = malloc(sizeof(char *) * (e + 1));
    a = 0;
    i = 0;
    while (i < e)
    {
        b = 0;
        while(xtab[a][b])
        {
            tab[i] = xtab[a][b];
            b++;
            i++;
        }
        a++;
    }
    tab[i] = 0;
    i = 0;
    diff = 0;
    a = 0;
    while (tab[i])
    {
        b = i + 1;
        while (tab[b])
        {
            diff = ft_strcmp(&tab[i], &tab[b]);
            if (diff > 0)
                ft_swap(&tab[i], &tab[b]);
            b++;
        }
        i++;
    }
    return (tab);
}

int ft_countarg(char *str, char *needle, char ***tab,int j)
{
    int i;
    int a;
    static int c = 0;

    a = 0;
    i = 0;
    if(j == 3)
                tab[c++] = malloc(sizeof(char *) * (ft_countarg(str, needle, tab, 4) + 1));
    else
    {
        while (str && *str)
        {
            str = strstr(str,needle);
            if (str)
            {
                if (j == 0 || j == 1 || j == 2)
                    tab[j][a] = str;
                str = str + 2;
                i++;
                a++;
            }
        }
        if (j == 0 || j == 1 || j == 2)
            tab[j][a] = 0;
    }
    return (i);
}

char **ft_tab(char *arg)
{
    int i;
    //int j;
    char **xtab;
    char ***tab;
    //int c;
    
    i = 0;
    tab = malloc(sizeof(char **) * 4);
    ft_countarg(arg,"%d", tab, 3);
    ft_countarg(arg,"%s", tab, 3);
    ft_countarg(arg,"%c", tab, 3);
    i = ft_countarg(arg, "%d", tab, 0) + ft_countarg(arg, "%s", tab, 1) + ft_countarg(arg, "c", tab, 2);
    tab[3] = 0;
    xtab = ft_rang(tab, i);
    return (xtab);
}

int main ()
{
    ft_tab("123%s349%s039%s28%c34%d");
}