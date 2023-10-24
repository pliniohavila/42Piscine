#include <stdio.h>

#define AR_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

int     ft_is_sort(int *tab, int length, int(*f)(int, int));
int     compare(int, int);

int     main(void)
{
    int    tab_1[] = {1, 2, 5, 3, 8};
    int    tab_2[] = {1, 3, 5, 30, 80};
    int    tab_3[] = {0, 4, 10, 10, 20};

    printf("[TAB_1] expect: 0 - received: %d\n", ft_is_sort(tab_1, AR_LENGTH(tab_1), &compare));
    printf("[TAB_2] expect: 1 - received: %d\n", ft_is_sort(tab_2, AR_LENGTH(tab_2), &compare));
    printf("[TAB_3] expect: 1 - received: %d\n", ft_is_sort(tab_3, AR_LENGTH(tab_3), &compare));
    return(0);
}

int     ft_is_sort(int *tab, int length, int(*f)(int, int))
{
    int     i;

    i = 0;
    while (i < (length - 1))
    {
        if (f(tab[i], tab[i + 1]) > 0)
            return (0);
        i++;
    }
    return (1);
}

int     compare(int a, int b)
{
    if (a < b) return (-1);
    return (a > b);
}