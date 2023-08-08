/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:10:36 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/26 13:10:38 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbl;

	nbl = nb;
	if (nbl < 0)
	{
		ft_putchar('-');
		nbl = -nbl;
	}
	if (nbl >= 10)
	{
		ft_putnbr(nbl / 10);
	}
	ft_putchar('0' + nbl % 10);
}
/*
#include <stdio.h>
int	main(void)
{
	int	src = -2147483648;

	printf("This ist the Src: %d\n", src);
	ft_putnbr(src);
}*/
