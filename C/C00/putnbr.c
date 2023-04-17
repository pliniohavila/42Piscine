#include "unistd.h"

void	putnbr(int nb);

int		main()
{
	putnbr(1849);
	putnbr(42);
	putnbr(-42);

	return (0);
}

void	putnbr(int nb)
{
	int		count;
	int		module;
	char 	string[7];
	char	eol;

	count = 6;
	eol = '\n';
	for(int i = 0; i < 7; i++)
	{
		string[i] = 0;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		string[0] = '-';
	}
 	while ((nb != 0))
	{
		module = nb % 10;
		string[count] = (module + 48); // sum 48 to ANCII representation of the nb
		nb = nb - module;
		nb = nb / 10;
		count--;
	}

	write(1, string, 7);
	write(1, &eol, 1);
}