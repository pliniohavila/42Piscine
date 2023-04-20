#include "unistd.h"

void	putnbr(int);

void    ft_ultimate_ft(int *********nbr) 
{
    putnbr(*********nbr);
}

int     main(void)
{
    int     ft;
    int     *p1;
    int     **p2;
    int     ***p3;
    int     ****p4;
    int     *****p5;
    int     ******p6;
    int     *******p7;
    int     ********p8;
    int     *********p9;

    ft = 42;
    p1 = &ft;
    p2 = &p1;
    p3 = &p2;
    p4 = &p3;
    p5 = &p4;
    p6 = &p5;
    p7 = &p6;
    p8 = &p7;
    p9 = &p8;

    ft_ultimate_ft(p9);
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