#include <stdarg.h>
#include <stdio.h>

// typedef struct s_list
// {
// int *content;
// struct s_list *next;
// }

char   **ft_flag(char *arg, char *str);
void   ft_swap(char **a, char **b);
int	   ft_strcmp(char **s1, char **s2);
char   **ft_rangadrs(char **tab, int e);
char   *ft_trimarg(char *arg);
char   *ft_realloc(char **arg);
int    ft_isparam(int a, int b);
int    ft_isflag(int a);
int    ft_count(char *arg);
int    *ft_indices(char **str);
void   ft_subprintf(int *indices, char **flags, va_list n, char **str);
char   *ft_untoa(unsigned int n);
char   *ft_printhexa(int n);
char   *ft_activeflag(char **flags, char **tab, char **etoiles);
int    ft_countetoiles(char *arg); 