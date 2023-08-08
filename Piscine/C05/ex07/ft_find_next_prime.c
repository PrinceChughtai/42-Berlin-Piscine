/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:51:06 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/07 14:48:12 by pchughta         ###   ########.fr       */
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
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb = nb + 2;
	}
}
/*
#include <stdio.h>
int main(void)
{
    int num = 15;
    int next_prime = ft_find_next_prime(num);

    printf("Next prime number after %d is: %d\n", num, next_prime);

    return 0;
}*/
