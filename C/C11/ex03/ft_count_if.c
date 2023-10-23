#include <stdio.h>

#define AR_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

int     ft_any(char **tab, int(*f)(char*));
int     check(char *ch);

int     main(void)
{
    char    *tab_1[] = {"000", "0010", "1010", "1010", "000", NULL};
    char    *tab_2[] = {"00", "0000", "000", NULL};

    printf("[TAB_1] expect: 3 - received: %d\n", ft_any(tab_1, &check));
    printf("[TAB_2] expect: 0 - received: %d\n", ft_any(tab_2, &check));

    return (0);
}

int     ft_any(char **tab, int(*f)(char*))
{
    int     count;

    count = 0;
    while (*tab != NULL)
    {
        if (f(*tab))
            count++;
        tab++;    
    }
    return (count);
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