#include "unistd.h"

void	ft_print_comb(void)
{
	int		k;
	char	to_print[5];

	k = 0;
	to_print[3] = ',';
	to_print[4] = ' ';

	while (k < 10)
	{
		for (int i = 1; i < 10; i++)
		{
			for (int j = i; j < 10; j++)
			{
				if ((k != i) & (i != j) & (k != j))
				{
					to_print[0] = k + 48;
					to_print[1] = i + 48;
					to_print[2] = j + 48;
					write(1, &to_print, 5);
				}
			}
		}
		k++;
	}
}

int		main(void)
{
	ft_print_comb();

	return (0);
}