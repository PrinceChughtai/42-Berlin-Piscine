/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:43:55 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/07 14:47:58 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long	i;

	if (nb <= 1)
		return (0);
	if (nb > 2 && nb % 2 == 0)
		return (0);
	if (nb == 2)
		return (1);
	i = 3;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
    int num = 2147483647;
    int result = ft_is_prime(num);

    printf("%d is %sprime.\n", num, result ? "" : "not ");

    return 0;
}*/
