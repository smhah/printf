#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <unistd.h>

// typedef struct s_list
// {
// int *content;
// struct s_list *next;
// }

int	ft_toupper(int a);
int ft_printf(const char*format, ...);
char   **ft_flag(char *arg, char *str);
void   ft_swap(char **a, char **b);
int	   ft_strcmp(char **s1, char **s2);
char   **ft_rangadrs(char **tab, int e);
char   *ft_trimarg(char *arg);
char   *ft_realloc(char **arg);
int    ft_isparam(int a, int b);
int    ft_isflag(int a);
int    ft_count(char *arg);
char   *ft_indices(char **str);
int   ft_subprintf(char *indices, char **flags, va_list n, char **str);
char   *ft_untoa(unsigned int n);
char   *ft_printhexa(unsigned int n);
int   ft_activeflag(char **flags, char **tab);
int    ft_countetoiles(char *arg);
int    ft_strcpy(char *str1, char *str2, int j);
char   *ft_reverse(char *str);
void   ft_activeS(char *flags, char **tab , int i, char **strnum);
int   ft_activeflagS(char **flags, char **tabs);
int ft_checkfirst(char *flags, int i);
int ft_checkfirst(char *flags, int i);
char	*ft_tabjoin2(char *s1, char **s2);
char	*ft_tabjoin(char **s1, char **s2);
void ft_delfirst(char **tab);
int ft_isflag2(char a);
char   *ft_replace(char *flag, char **etoiles, int *e);
void    ft_modify(char **flag, char **etoiles);
int ft_cnd1(int a, int i);
int ft_cnd2(int a,int b,int i, char *flags);
char    *ft_verse(char **str);
size_t	ft_strlen(const char *str);
int ft_cnd2s(int a,int b,int i, char *flags);
int    ft_activeC(char *flags, char **tab , int i, char **strnum);
int ft_activeflagC(char **flags, char **tab);
int ft_isdigit(int a);
int	ft_isalpha(int a);
int  ft_activeflagpercent(char **flags, char **tab);
void    ft_activepercent(char *flags, char **tab , int i, char **strnum);
void    ft_flagmoin(char **tab, char **add, int indice, int len);
int			ft_atoi(const char *str);
int	ft_isalpha(int a);
int     ft_isnum(char **tab);
int     ft_countadresse(size_t n);
void    ft_setup(char **rev);
char    *ft_reverse(char *str);
char    *ft_printadresse(size_t n);
char	*ft_strdup(const char *str);
void    ft_putc(char c);
void    ft_puts(char *str);
void ft_free1(char **strnum);
void ft_toactive(char **tab, char **flags, char **str, int i);
void    ft_flagdigitS(char **tab, char **add,int len);
void    ft_flagmoinS(char **tab, char **add, int len);
void    ft_flagpoint(char **tab, char **add, int indice, int len);
void    ft_flagdigit(char **tab, char **add, int indice, int len);
