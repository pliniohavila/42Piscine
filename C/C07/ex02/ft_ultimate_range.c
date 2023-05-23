#include <stdio.h>
#include <stdlib.h>

int     ft_ultimate_range(int **range, int min, int max)
{
    int     diff;
    int     i;

    if (min >= max)
        return (0);

    diff = max - min;
    *range = (int *)malloc(sizeof(int) * diff);
    if (range == NULL)
        return (-1);

    i = 0;
    while (min < max)
    {
        (*range)[i] = min;
        i++;
        min++;
    }
    return diff;
}

int     main(void)
{
    int     *range;
    int     len_range;

    range = NULL;    
    len_range = ft_ultimate_range(&range, 0, 11);
    if (range == NULL)
        return (-1);

    printf("Len Range: %d\n", len_range);
    free(range);

    return (0);
}