/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:58:06 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/07 14:49:22 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (1);
	}
	else
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
}
/*
#include <stdio.h>
int main() {
    int num = 5;
    int power = 3;
    int result = ft_recursive_power(num, power);

    printf("%d to the Power of %d is equal to %d.", num, power, result);

    return 0;
}*/
