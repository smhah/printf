char **ft_flag(char *arg, char *str)
{
	int count;
	int i;
	char **tab;
	int save;
	int a;

	count = ft_count(str);
	tab = malloc(sizeof(char *) * count + 1);
	a = 0;
	i = 0;
	while(arg[i])
	{
		save = 0;
		if (arg[i++] == '%')
		{
			save = i;
			while(ft_isflag(arg[i]))
				i++;
			if((ft_isparam(arg[i]) >= 0))
				tab[a++] = ft_substr(arg, save, i - save);
		}
		i++;
	}
	tab[a] = NULL;
	return (tab);
}
int main ()
{
	//ft_tab("%112dddkfjhsdfjk%cdslgkdfgl%sfldkgjdf%ssdfjdfg%c", 12, 'c', "TRI", 'C');
	//printf("%3654654d\n", 500, 50);
	//ft_flag("%123123d%123234d\n", 500, 50);
	ft_flag("asdas%dsd%---12sdsdsd%.12c","%d%s%c");
}