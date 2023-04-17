/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pliniocode <pliniohrcode@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:13:49 by pliniocode        #+#    #+#             */
/*   Updated: 2023/04/12 16:54:44 by pliniocode       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	letter;
	char	eol;

	letter = 'a';
	eol = '\n'
		do
	{
		write(1, &letter, 1);
		write(1, &eol, 1);
		letter++;
	}
	while (letter != 'z');
}
