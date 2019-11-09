void ft_printf(const char *arg, ...)
{
    char *str;
    int  *indices;
    char **flags;

    str = ft_trimarg(arg);
    indices = ft_indices(str);
    flags = ft_flag(arg, str);
}