#include "stdio.h"

void    ft_rev_int_tb(int *tab, int size)
{
    int     tmp;

    for (int i = 0; i < ((size - 1) / 2); i++)
    {
        tmp = tab[i];
        tab[i] = tab[size - 1 - i];
        tab[size - 1 - i] = tmp;
    }
}

int     main(void)
{
    int     size;

    int     tab[] = {2, 5, 4, 6, 8};

    size = 5;

    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    ft_rev_int_tb(tab, size);
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
}