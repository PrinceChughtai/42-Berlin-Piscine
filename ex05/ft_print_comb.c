/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:24:21 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/20 16:24:24 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	writer(char x, char y, char z)
{
	write(1, &x, 1);
	write(1, &y, 1);
	write(1, &z, 1);
	if (x != 55 || y != 56 || z != 57)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	x;
	char	y;
	char	z;

	x = 48;
	while (x <= 55)
	{
		y = x + 1;
		while (y <= 56)
		{
			z = y + 1;
			while (z <= 57)
			{
				writer(x, y, z);
				z++;
			}
			y++;
		}
		x++;
	}
}
