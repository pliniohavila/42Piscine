#include "stdio.h"
#include "ft_is_negative.h"

int main(void)
{
	printf("\n[+] TEST WITH 4\n");
	ft_is_negative(4);
	printf("\n[+] TEST WITH -4\n");
	ft_is_negative(-4);
	printf("\n[+] TEST WITH -54\n");
	ft_is_negative(-54);
	printf("\n[+] TEST WITH 7\n");
	ft_is_negative(7);
	return (0);
}