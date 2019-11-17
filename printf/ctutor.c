#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

static char	*ft_unsigneditoa(char *s, unsigned int n, int *p)
{
	if (n <= 9)
		s[*p] = n + 48;
	else
	{
		ft_unsigneditoa(s, n / 10, p);
		*p = *p + 1;
		ft_unsigneditoa(s, n % 10, p);
	}
	return (s);
}

static char	*condition1(int n, int len, int *p)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (len + 2));
	if (str == 0)
		return (0);
	str[*p] = '-';
	*p = *p + 1;
	ft_unsigneditoa(str, n * -1, p);
	str[*p + 1] = '\0';
	return (str);
}

static char	*condition2(int n, int len, int *p)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n <= 9)
		str[*p] = n + 48;
	else
		ft_unsigneditoa(str, n, p);
	str[*p + 1] = '\0';
	return (str);
}

static char	*condition3(int len)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (len + 2));
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		b;
	int		len;
	int		*p;
	int		i;

	len = 0;
	b = n;
	while (b != 0)
	{
		b = b / 10;
		len++;
	}
	i = 0;
	p = &i;
	if (n < 0)
		str = condition1(n, len, p);
	else if (n > 0)
		str = condition2(n, len, p);
	else
		return (condition3(len));
	return (str);
}

int ft_countarg(char *str, char *needle)
{
	int i;

	i = 0;
	while (str)
	{
		str = strstr(str,needle);
		if (str)
		{
			str = str + 2;
			i++;
		}
	}
	return (i);
//	printf("|%d|", i);
}

char **ft_remplir(char **str, char *arg, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		str[0][j] = arg[j];
		j++;
	}
	return (str);
}

void	ft_printf(char *arg, ...)
{
	va_list n;
	char	*find;
	char	*str;
	int		len;
	char 	**tab;
	int		a;
	int		b;
	int		i;

	if (ft_countarg(arg,"%d"))
	{	
		b = 0;
		a = 0;
		tab = NULL;
		i = 0;
		i = ft_countarg(arg,"%d");
		va_start(n, arg);
		tab = malloc(sizeof(char *) * (i + 1));
		while(i > 0)
		{
			tab[a] = strdup(ft_itoa(va_arg(n, int)));
			b = b + strlen(tab[a]);
			a++;
			i--;
		}
		i = ft_countarg(arg,"%d");
		tab[a] = 0;
		a = 0;
		len = b + strlen(arg) - 2 * i;
		str = (char *)malloc(sizeof(char) * (len + 1));
		i = 0;
		while(i < len - 1)
		{
			find = strstr(arg, "%d");
			while (arg != find && *arg)
			{
				str[i] = *arg;
				i++;
				arg++;
			}
			b = 0;
			while(tab[a] && tab[a][b])
				str[i++] = tab[a][b++];
			arg = arg + 2;
			a++;
		}
		str[i] = '\0';
	}
	printf(“%s”, str);
}

int main ()
{
	ft_printf("%d", 9);
	//printf("%d\n", ft_countarg("numberone:%dnumbertwo%d", "%d"));
}
