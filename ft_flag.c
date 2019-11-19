#include "libft/libft.h"
#include "ft_printf.h"

char **ft_flag(char *arg, char *str)
{
	int count;
	int i;
	char **tab;
	int save;
	int a;

	count = ft_count(str);
	tab = malloc(sizeof(char *) * (count + 1));
	a = 0;
	i = 0;
	while(arg[i])
	{
		save = 0;
		if (arg[i++] == '%')
		{
			save = i;
			while(ft_isflag(arg[i]) || arg[i] == '*')
				i++;
			if((ft_isparam(arg[i], 0) >= 0))
			{
				tab[a] = ft_substr(arg, save, i - save);
				a++;
			}
		}
	}
	tab[a] = NULL;
	// a = 0;
	// while (tab[a] != NULL)
	// {
	// 	printf("%s\n", tab[a++]);
	// }
	return (tab);
}
// int main ()
// {
// 	//ft_tab("%112dddkfjhsdfjk%cdslgkdfgl%sfldkgjdf%ssdfjdfg%c", 12, 'c', "TRI", 'C');
// 	//printf("%3654654d\n", 500, 50);
// 	//ft_flag("%123123d%123234d\n", 500, 50);
// 	ft_flag("a%dsd%-12sn%.12c%x%*-234*X","%d%s%c%x%X");
// }