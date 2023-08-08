/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:51:18 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/07 14:46:20 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	result = 1;
	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	i = 1;
	while (i <= nb)
	{
		result *= i;
		i++;
	}
	return (result);
}
/*
#include <stdio.h>
int main()
{
	int num = 5;
	int factorial = ft_iterative_factorial(num);

	printf("The factorial of %d is %d.", num, factorial);

	return (0);
}*/
