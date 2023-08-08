/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:25:16 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/22 16:25:19 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

//	Including and Introducing ft_putchar 
void	ft_putchar(char c);

// Function to display the top and bottom edges of the rush
void	print_horizontal(int width, char left, char right)
{
	int	length;

	length = 0;
	ft_putchar(left);
	while (length < width -2)
	{
		ft_putchar('-');
		length++;
	}
	if (width > 1)
	{
		ft_putchar(right);
	}
	ft_putchar('\n');
}

// Function to display the vertical edges of the rush
void	print_vertical(int width)
{
	int	length;

	length = 1;
	ft_putchar('|');
	while (length <= width - 2)
	{
		ft_putchar(' ');
		length++;
	}
	if (width > 1)
	{
		ft_putchar('|');
	}
	ft_putchar('\n');
}

// Function to create the rush pattern
void	rush(int x, int y)
{
	int	length;

	length = 1;
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	print_horizontal(x, 'o', 'o');
	while (length <= y - 2)
	{
		print_vertical(x);
		length++;
	}
	if (y > 1)
	{
		print_horizontal(x, 'o', 'o');
	}
	ft_putchar('\n');
}
