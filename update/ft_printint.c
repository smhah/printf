void	ft_printint(char *arg, ...)
{
	va_list n;
	char	*find;
	char	*str;
	int		len;
	char 	***tab;
	int		a;
	int		b;
	int		c;
	int		i;
	int		compteur;
	int 	somme;

	tab = NULL;
	compteur = 0;
	a = 0;
	if (ft_countarg(arg,"%d"))
		compteur++;
	if (ft_countarg(arg,"%s"))
		compteur++;
	if (ft_countarg(arg,"%d"))
	{	
		b = 0;
		i = 0;
		somme = 0;
		i = ft_countarg(arg,"%d");
		va_start(n, arg);
		tab[a] = malloc(sizeof(char *) * (i + 1));
		while(i > 0)
		{
			tab[a][b] = ft_strdup(ft_itoa(va_arg(n, int)));
			somme = somme + ft_strlen(tab[a][b]);
			b++;
			i--;
		}
		i = ft_countarg(arg,"%d");
		tab[a][b] = 0;
		b = 0;
		len = somme + ft_strlen(arg) - 2 * i;
		str = (char *)malloc(sizeof(char) * (len + 1));
		i = 0;
		while(i < len)
		{
			find = strstr(arg, "%d");
			while (arg != find && *arg)
			{
				str[i] = *arg;
				i++;
				arg++;
			}
			c = 0;
			while(tab[a][b] && tab[a][b][c])
				str[i++] = tab[a][b][c++];
			arg = arg + 2;
			b++;
		}
		str[i] = '\0';
	}
	ft_putstr_fd(str,1);
}