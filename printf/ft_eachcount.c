int ft_d(int *indices, int count)
{
    int c;
    int i;

    c = 0;
    while(indices[i] < count)
    {
        if(indices[i] == 0)
            c++;
        i++;
    }
    return(c);
}

int ft_c(int *indices, int count)
{
    int c;
    int i;

    c = 0;
    while(indices[i] < count)
    {
        if(indices[i] == 1)
            c++;
        i++;
    }
    return(c);
}

int ft_s(int *indices, int count)
{
    int c;
    int i;

    c = 0;
    while(indices[i] < count)
    {
        if(indices[i] == 2)
            c++;
        i++;
    }
    return(c);
}

int ft_p(int *indices, int count)
{
    int c;
    int i;

    c = 0;
    while(indices[i] < count)
    {
        if(indices[i] == 3)
            c++;
        i++;
    }
    return(c);
}

int ft_i(int *indices, int count)
{
    int c;
    int i;

    c = 0;
    while(indices[i] < count)
    {
        if(indices[i] == 4)
            c++;
        i++;
    }
    return(c);
}