#include "ft_putchar.h"
#include "stdio.h"

int main(void)
{
	printf("[+] ft_putchar test: \n");
	printf("[+] Test with: a, b, y\n");
    ft_putchar('a');
	printf("\n");
	ft_putchar('b');
	printf("\n");
	ft_putchar('y');
	printf("\n");
	printf("[+]\n");

    return (0);
}

// gcc -Wall -Wextra -Werror -o test ft_putchar.h test_ft_putchar.c