#include "ft_printf.h"

extern int g_i;
extern int g_j;
extern int g_k;

void ft_putc(char c)
{
        write(1, &c, 1);
}

int     ft_putczero(char c)
{
        write(1, &c, 1);
        return (1);
}

void 	ft_puts(char *str)
{
        int i;

        i = 0;
        while(str[i] != '\0')
                ft_putc(str[i++]);
}

void 	ft_flagmoinC(char **add, char **tab, int len)
{
	*add = memset(*add,' ',len);
	(*add)[len] = '\0';
	ft_putc((*tab)[0]);
	ft_puts(*add);
}

void    ft_flagdigitC(char **tab, char **add, int len)
{
		*add = memset(*add,' ',len);
		(*add)[len] = '\0';
		ft_puts(*add);
		ft_putc((*tab)[0]);
}
int    ft_activeC(char *flags, char **tab , int i, char **strnum)
{
	char *add;
	int ind;
	int len;

	ind = 0;
	len = atoi((*strnum)) - 1;
	if (len < 0)
	{       
		ft_free1(strnum);
		if (i == 0)
				ft_putc((*tab)[0]);
	return (1);
	}
	add = malloc(sizeof(char) * len);
	if (ft_checkfirst(flags, i))
			ind = 1;
	if(ind > 0 && flags[i] == '-' &&
		 (flags[i - 1] != '-' || flags[i + 1] != '-'))
		ft_flagmoinC(&add, tab, len);
	else if (ft_isdigit(flags[i]))
		ft_flagdigitC(tab, &add, len);
	free(add);
	ft_free1(strnum);
	return(len + 1);
}

int ft_toactiveC(char **tab, char **flags, char **str, int i)
{
	if (flags[0][i] == '-' && flags[0][i + 1] == '-')
	{
		ft_free1(str);
		return (0);
	}
	else
	{
		if((*str)[0])
		   *str = ft_verse(str);
		return (ft_activeC(*flags, &(*tab), i, str));
	}
	return (0);
}

int  ft_activeflagC(char **flags, char **tab)
{
        char *str;
 
        g_k = 0;
        str = NULL;
        if(**flags != '\0')
        {
			g_i = ft_strlen(*flags);
			g_j = 0;
			while(--g_i >= 0)
			{
				if (str == NULL && (g_j = 0) >= 0)
						str = malloc(ft_strlen((*flags)) + 1);
				if(ft_isdigit((*flags)[g_i]))
						str[g_j++] = (*flags)[g_i];
				if(str && ft_cnd2((*flags)[g_i], str[g_j - 1], g_i,*flags) > 0 &&
					(str[g_j] = '\0') == '\0')
						if (!(g_k += ft_toactiveC(tab, flags, &str, g_i)))
							break;
				if(str && ft_cnd2s((*flags)[g_i], str[g_j -1 ], g_i, &(*flags)[0]) < 0)
						ft_free1(&str);
			}
        }
        else
                return (ft_putczero((*tab)[0]));
        return (g_k);
}