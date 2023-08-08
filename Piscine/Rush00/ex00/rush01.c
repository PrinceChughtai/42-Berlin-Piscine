/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:54:24 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/22 11:54:26 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

//	Including and Introducing ft_putchar 
void	ft_putchar(char c);

// Function to display the row of the rush
void	print_horizontal(int width, char left, char middle, char right)
{
	int	x_length;

	x_length = 1;
	ft_putchar(left);
	while (x_length <= width -2)
	{
		ft_putchar(middle);
		x_length++;
	}
	if (width > 1)
	{
		ft_putchar(right);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	y_length;

	y_length = 1;
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	print_horizontal(x, '/','*', '\\');
	while (y_length <= y - 2)
	{
		print_horizontal(x, '*', ' ', '*');
		y_length++;
	}
	if (y > 1)
	{
		print_horizontal(x, '\\', '*', '/');
	}
	ft_putchar('\n');
}
