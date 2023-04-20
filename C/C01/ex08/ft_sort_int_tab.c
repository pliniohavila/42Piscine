#include "stdio.h"

void    ft_swap(int *a, int *b)
{
    int     tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    ft_sort_int_tab(int *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (tab[j] < tab[i])
                ft_swap((tab + i), (tab + j));
        }
    }
}

int     main(void)
{
    int     size;

    int     tab[] = {9, 5, 2, 4, 8};
    size = 5;

    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    ft_sort_int_tab(tab, size);
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }

    return (0);
}

