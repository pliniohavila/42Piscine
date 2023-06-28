
int     ft_strcmp(char *s1, char *s2)
{
    unsigned char   c1;
    unsigned char   c2;

    while (*s1 != '\0')
    {
        c1 = *s1++;
        c2 = *s2++;
        if (c1 != c2)
            return c1 < c2 ? -1 : 1;
    }

    return (0);
}
