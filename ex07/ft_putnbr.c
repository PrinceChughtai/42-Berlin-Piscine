/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:38:23 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/22 10:38:25 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	digiting(int num)
{
	char	digit;

	if (num / 10 != 0) 
	{
		digiting(num / 10);
	}
	digit = '0' + (num % 10);
	write(1, &digit, 1);
}

void	ft_putnbr(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	else if (num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	digiting(num);
}
