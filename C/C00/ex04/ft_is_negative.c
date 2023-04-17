/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pliniocode <pliniohrcode@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:17:51 by pliniocode        #+#    #+#             */
/*   Updated: 2023/04/13 08:27:06 by pliniocode       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_is_negative(int n)
{
	char	is_negative, is_positive;

	is_negative = 'N';
	is_positive = 'P';

	if (n < 0)
		write(1, &is_negative, 1);
	else
		write(1, &is_positive, 1);
}
