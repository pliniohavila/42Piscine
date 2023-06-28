#include <stdio.h>
#include "libft.h"


int     main(void)
{
    int     a;
    int     b;
    char    *str;

    a = 42;
    b = 21;
    str = "Ecole42"; 
    printf("SWAP(%d, %d): ", a, b);
    ft_swap(&a, &b);
    printf("%d, %d\n", a, b);
    ft_putstr("PUTSTR: ");
    ft_putstr(str);
    printf("\n");
    printf("LEN(%s): %d\n", str, ft_strlen(str));
    printf("STRCMP(%s, hello): %d", str, ft_strcmp(str, "hellos"));
    printf("\n");

    return (0);
}
