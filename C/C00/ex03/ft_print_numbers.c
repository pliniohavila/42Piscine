/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pliniocode <pliniohrcode@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:02:04 by pliniocode        #+#    #+#             */
/*   Updated: 2023/04/13 08:14:51 by pliniocode       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_print_numbers(void)
{
	int		number;
	char	space;

	number = 0 + 48;
	space = ' ';
	while (number <= (48 + 9))
	{
		write(1, &number, 1);
		write(1, &space, 1);
		number++;
	}
}