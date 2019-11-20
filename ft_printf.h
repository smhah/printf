/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:38:41 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 14:38:52 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		ft_toupper(int a);
int		ft_printf(const char*format, ...);
char	**ft_flag(char *arg, char *str);
char	*ft_trimarg(char *arg);
int		ft_isparam(int a, int b);
int		ft_isflag(int a);
int		ft_count(char *arg);
char	*ft_indices(char **str);
int		ft_subprintf(char *indices, char **flags, va_list n, char **str);
char	*ft_untoa(unsigned int n);
char	*ft_printhexa(unsigned int n);
int		ft_activeflag(char **flags, char **tab);
int		ft_countetoiles(char *arg);
int		ft_strcpy(char *str1, char *str2, int j);
char	*ft_reverse(char *str);
void	ft_actives(char *flags, char **tab, int i, char **strnum);
int		ft_activeflags(char **flags, char **tabs);
int		ft_checkfirst(char *flags, int i);
char	*ft_tabjoin2(char *s1, char **s2);
char	*ft_tabjoin(char **s1, char **s2);
void	ft_delfirst(char **tab);
int		ft_isflag2(char a);
void	ft_modify(char **flag, char **etoiles);
int		ft_cnd1(int a, int i);
int		ft_cnd2(int a, int b, int i, char *flags);
char	*ft_verse(char **str);
int		ft_cnd2s(int a, int b, int i, char *flags);
int		ft_activec(char *flags, char **tab, int i, char **strnum);
int		ft_activeflagc(char **flags, char **tab, char **str);
int		ft_activeflagpercent(char **flags, char **tab);
void	ft_activepercent(char *flags, char **tab, int i, char **strnum);
void	ft_flagmoin(char **tab, char **add, int indice, int len);
int		ft_isnum(char **tab);
int		ft_countadresse(size_t n);
void	ft_setup(char **rev);
char	*ft_printadresse(size_t n);
void	ft_putc(char c);
void	ft_puts(char *str);
void	ft_free1(char **strnum);
void	ft_toactive(char **tab, char **flags, char **str, int i);
void	ft_flagdigits(char **tab, char **add, int len);
void	ft_flagmoins(char **tab, char **add, int len);
void	ft_flagpoint(char **tab, char **add, int indice, int len);
void	ft_flagdigit(char **tab, char **add, int indice, int len);
int		ft_checknegative(char **tab, char *flags, int i, int *len);
int		ft_putczero(char c);
void	ft_flagdigitc(char **tab, char **add, int len);
void	ft_flagmoinc(char **add, char **tab, int len);
char	*ft_trimarg(char *arg);
char	*ft_trim(char **tab, char **strnum);
void	freeall(char **tab, char **flags, char **str, char **indices);
char	*ft_replace(char *flag, char **etoiles, int *e);
char	*ft_char(char s);
char	*ft_str(char *s);
void	ft_freeadresse(va_list n, char **tab);
char	*ft_toper(char *str);

#endif
