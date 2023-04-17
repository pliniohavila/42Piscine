/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pliniocode <pliniohrcode@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:39:32 by pliniocode        #+#    #+#             */
/*   Updated: 2023/04/14 12:41:18 by pliniocode       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void 	format_print(char *, int, int);
void	ft_print_comb2(void);

int main(void)
{
	ft_print_comb2();

	return(0);
}

void	ft_print_comb2(void)
{
	char	to_print[8];

	to_print[2] = 32; // 32 is ANCII code to blank space
	to_print[3] = 32;
	to_print[6] = ',';
	to_print[7] = 32;
	// to_print = {[2] = 32, [3] = 32, [6] = '6', [7] = 32};
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (i != j)
			{
				format_print(to_print, i, j);
				write(1, to_print, 8);

			}
		}
	}
}

void 	format_print(char *buf, int i, int j)
{
	if (i < 10)
	{
		buf[0] = '0';
		buf[1] = i + 48;
	}
	else
	{
		buf[0] = ((i - (i % 10)) / 10) + 48;
		buf[1] = (i % 10) + 48;
	}
	if (j < 10)
	{
		buf[3] = '0';
		buf[4] = j + 48;
	}
	else
	{
		buf[3] = ((j - (j % 10)) / 10) + 48;
		buf[4] = (j % 10) + 48;
	}
}