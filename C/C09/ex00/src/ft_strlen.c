
int     ft_strlen(char *str)
{
    register int    i;

    i = 0;
    while(str[i] != '\0')
        i++;

    return (i);
}
