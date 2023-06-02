#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int min, int max)
{
    int     len;
    int     i;
    int     new_max;
    int     *inverted;

    len = max - min;
    if (len <= 0)
        return NULL;

    inverted = (int *)malloc(len * sizeof(int));
    if (inverted == NULL)
        return NULL;

    i = 0;
    new_max = max - 1;
    while (new_max >= min)
    {
        inverted[i] = new_max;
        new_max--;
        i++;
    }

    return inverted;
}

int     main(void)
{
    int     min;
    int     max;
    int     len;
    int     *inverted;
    int     i;

    min = 10;
    max = 50;
    len = max - min;

    inverted = ft_range(min, max);
    if (inverted == NULL)
        return (-1);

    i = 0;
    while (i < len)
    {
        printf("%d, ", inverted[i]);
        i++;
    }
    printf("\n");
    
    free(inverted);
    return (0);
}