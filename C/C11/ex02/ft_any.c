#include <stdio.h>

#define AR_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#define LEN 5

int     ft_any(char **tab, int(*f)(char*));
int     check(char *ch);

int     main(void)
{
    char    *tab_1[] = {"000", "0000", "1010", NULL};
    char    *tab_2[] = {"000", "0000", "000", NULL};

    printf("[TAB_1] expect: 1 - received: %d\n", ft_any(tab_1, &check));
    printf("[TAB_2] expect: 0 - received: %d\n", ft_any(tab_2, &check));

    return (0);
}

int     ft_any(char **tab, int(*f)(char*))
{
    int     i;

    i = 0;
    while (tab[i] != NULL)
    {
        if (f(tab[i]) == 1)
            return (1);
        i++;
    }
    return (0);
}

int     check(char *ch)
{
    while (*ch != '\0')
    {
        if (*ch != 48)
            return (1);
        ch++;
    }
    return (0);
}