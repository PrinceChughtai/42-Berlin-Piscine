/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyCitiy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:32:29 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/30 21:34:39 by prchught         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ourFunctions.h"

int	solve(int **working_array, int *entry, int pos, int size)
{
	int	i;

	if (pos == size * size)
		return (1);
	i = 0;
	while (++i <= size)
	{
		if (check_double(working_array, pos, i, size) == 0)
		{
			working_array[pos / size][pos % size] = i;
			if (check_case(working_array, pos, entry, size) == 0)
			{
				if (solve(working_array, entry, pos + 1, size)
					== 1)
					return (1);
			}
			else
				working_array[pos / size][pos % size] = 0;
		}
	}
	return (0);
}

void	display_solution(int **working_array, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			ft_putnbr(working_array[i][j]);
			if (!(j == size - 1))
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
