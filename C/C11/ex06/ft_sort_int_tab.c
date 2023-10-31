#include <stdio.h>

#define LEN 5

void    print (int *ar[], int len)
{
    int     i;

    i = 0;
    fflush (stdout);
    while (i < len)
        {
        printf ("%d ", *(ar[i]));
        i++;
        }
    printf ("\n");
}

void        swap (int **a, int **b)
{
    int *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void        sort (int **ar, int len)
{
    int i;
    int k;

    i = 0;
    while (i < len) 
        {
        k = 0;
        while (k < len - 1)
        {
            if (*ar[k] > *ar[k + 1])
                swap (&ar[k], &ar[k + 1]);
            k++;
        }
        i++;
    }
}

int     main(void)
{
    int *ar[LEN];
    int a, b, c, d, e;

    a = 5;
    b = 1;
    c = 7;
    d = 3;
    e = 8;

    ar[0] = &a;
    ar[1] = &b;
    ar[2] = &c;
    ar[3] = &d;
    ar[4] = &e;

    printf("Before sorting: ");
    print(ar, LEN);
    sort(ar, LEN);
    printf("After sorting: ");
    print(ar, LEN);
    return 0;
}
