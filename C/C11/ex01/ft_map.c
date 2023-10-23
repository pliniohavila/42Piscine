#include <stdio.h>
#include <stdlib.h>

#define AR_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

int     *ft_map(int *tab, int length, int(*f)(int));
int     sum(int nb);
int     multi(int nb);
void    print(int *data, int length);

int     main(void)
{   
    int     tab[] = {2, 5, 24, 7, 64};
    int     *map_sum;
    int     *map_multi;
    int     length;

    length = AR_LENGTH(tab);
    print(tab, length);
    map_sum = ft_map(tab, length, &sum);
    map_multi = ft_map(tab, length, &multi);
    print(map_sum, length);
    print(map_multi, length);

    free(map_sum);
    free(map_multi);
    return (0);
}

int     *ft_map(int *tab, int length, int(*f)(int))
{
    int     *res;
    int     i;

    res = (int*)malloc(sizeof(int) * length);
    if (res == NULL)
        return NULL;
    i = 0;
    while (i < length)
    {
        res[i] = f(tab[i]);
        i++;
    }
    return (res);
}

int     sum(int nb)
{
    return (nb + nb);
}
int     multi(int nb)
{
    return (nb * 3);
}

void    print(int *data, int length)
{
    int     i;

    i = 0;
    while (i < length)
        printf("%d ", data[i++]);
    printf("\n");
}

