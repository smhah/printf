#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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
        char **xtab;
        char ***tab;
        int c;
        //int j;
        int *tableau;
        int k;

        i = 0;
        tab = malloc(sizeof(char **) * 4);
        ft_countarg(arg,"%d", tab, 3);
        ft_countarg(arg,"%s", tab, 3);
        ft_countarg(arg,"%c", tab, 3);
        i = ft_countarg(arg, "%d", tab, 0) + ft_countarg(arg, "%s", tab, 1) + ft_countarg(arg, "%c", tab, 2);
        tableau = malloc(sizeof(int) * i);
        tab[3] = 0;
        xtab = ft_rang(tab, i);
        i = 0;
        printf("\n");
        while(xtab[i])
        {
                printf("%p\n", xtab[i]);
                i++;
        }
        i = 0;
        c = 0;
        printf("\n");
        while(tab[i])
        {
                c = 0;
                while(tab[i][c])
                {
                        k = 0;
                        while (xtab[k])
                        {
                                if (i == 0 && tab[i][c] == xtab[k])
                                        tableau[k] = 0;
                                else if (i == 1 && tab[i][c] == xtab[k])
                                        tableau[k] = 1;
                                else if (i == 2 && tab[i][c] == xtab[k])
                                        tableau[k] = 2;
                                k++;
                        }
                        c++;
                }
                i++;
        }
        i = 0;
        while (i < 8)
        {
                printf("%d;", tableau[i]);
                i++;
        }
        return (xtab);
}
