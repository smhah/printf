#include <stdarg.h>

char   **ft_rang(char ***tab, int e);
int    ft_countarg(char *str, char *needle, char ***tab,int j);
//int	   *ft_indices(char ***tab, char **xtab, int *indices);
char   **ft_tab(char *arg, char **indices);
char   **ft_flag(char *arg, char *str, int *ft_indices);
void   ft_swap(char **a, char **b);
int	   ft_strcmp(char **s1, char **s2);
char   **ft_rangadrs(char **tab, int e);
char   *ft_trimarg(char *arg);
char   *ft_realloc(char **arg);
int    ft_isparam(int a);
int    ft_isflag(int a);
int    ft_count(char *arg);
int    *ft_indices(char **str, int count);
void   ft_subprintf(int *indices, char **flags, va_list n, char **str);
char   *ft_untoa(unsigned int n);
char   *ft_printhexa(int n);
char   *ft_activeflag(char **flags, char **tab, char **etoiles);