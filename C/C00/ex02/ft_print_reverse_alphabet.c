/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pliniocode <pliniohrcode@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 07:38:19 by pliniocode        #+#    #+#             */
/*   Updated: 2023/04/13 07:56:46 by pliniocode       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_print_reverse_alphabet(void)
{
	char	letter;

	letter = 'z';
	do
	{
		write(1, &letter, 1);
		letter--;
	}
	while (letter >= 'a');
}
