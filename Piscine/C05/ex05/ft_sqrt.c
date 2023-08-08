/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:38:13 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/07 14:47:47 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	x;
	long	y;

	x = nb;
	y = 1;
	if (nb <= 0)
		return (0);
	while (x - y > 1)
	{
		x = (x + y) / 2;
		y = nb / x;
	}
	if (x * x == nb)
		return (x);
	else
		return (0);
}

/*
#include <stdio.h>
int main()
{
    int num = 25;
    int result = ft_sqrt(num);

    printf("Square root of %d: %d\n", num, result);

    return 0;
}*/
/*
int	ft_sqrt(int nb)
{
	long	low;
	long	high;
	long	mid;
	long	square;

	low = 1;
	high = nb;
	if (nb <= 0)
		return (0);
	while (low <= high)
	{
		mid = (low + high) / 2;
		square = mid * mid;
		if (square == nb)
			return (mid);
		if (square < nb)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (high);
}*/
