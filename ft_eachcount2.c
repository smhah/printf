int ft_u(int *indices, int count)
{
    int c;
    int i;

    c = 0;
    while(indices[i] < count)
    {
        if(indices[i] == 5)
            c++;
        i++;
    }
    return(c);
}

int ft_x(int *indices, int count)
{
    int c;
    int i;

    c = 0;
    while(indices[i] < count)
    {
        if(indices[i] == 6)
            c++;
        i++;
    }
    return(c);
}

int ft_X(int *indices, int count)
{
    int c;
    int i;

    c = 0;
    while(indices[i] < count)
    {
        if(indices[i] == 7)
            c++;
        i++;
    }
    return(c);
}

int ft_percent(int *indices, int count)
{
    int c;
    int i;

    c = 0;
    while(indices[i] < count)
    {
        if(indices[i] == 8)
            c++;
        i++;
    }
    return(c);
}
