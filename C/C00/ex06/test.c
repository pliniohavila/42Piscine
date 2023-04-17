#include "stdio.h"

int		main(void)
{
	int		a, b;
	b = (a = 6, a += 4, a += 1);

	// int a=1, b=2, c=3;
	// int i = (a, b);

	printf("%d \n", b);

	return (0);
}