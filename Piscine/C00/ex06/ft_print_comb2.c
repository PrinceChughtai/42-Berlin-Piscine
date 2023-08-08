/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:01:21 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/20 19:02:02 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	num2 = 1;
	while (num1 <= 98)
	{
		while (num2 <= 99)
		{
			ft_putchar('0' + num1 / 10);
			ft_putchar('0' + num1 % 10);
			ft_putchar(' ');
			ft_putchar('0' + num2 / 10);
			ft_putchar('0' + num2 % 10);
			if (num1 != 98 || num2 != 99)
			{
				write(1, ", ", 2);
			}
			num2++;
		}
		num1++;
		num2 = num1 + 1;
	}
}
