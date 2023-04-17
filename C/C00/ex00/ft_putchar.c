/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pliniocode <pliniohrcode@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:03:04 by pliniocode        #+#    #+#             */
/*   Updated: 2023/04/12 16:13:44 by pliniocode       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char);

void	ft_putchar(char c)
{
	int	fd;

	fd = 1;
	write(fd, &c, 1);
}
