#include<stdio.h>
#include<stdlib.h>

int main ()
{
    int **tab;
    int i;
    int j;

    tab = (int *)(malloc(sizeof(int * ) * 4));
    i = 0;
    while (i < 4)
    {
        tab[i] = malloc(12);
        tab[i] = 3;
        j = 0;
        while(j < 3)
        {
            tab[i][j++] = 2;
        }
        i++;
    }
    printf("%ls", tab[0]);
}
