/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:33:36 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/30 15:33:38 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ourFunctions.h"

int	check_col_up(int **working_array, int pos, int *entry, int size)
{
	int	i;
	int	max;
	int	visible_towers;

	i = 0;
	max = 0;
	visible_towers = 0;
	if (pos / size == size - 1)
	{
		while (i < size)
		{
			if (working_array[i][pos % size] > max)
			{
				max = working_array[i][pos % size];
				visible_towers++;
			}
			i++;
		}
		if (entry[pos % size] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_row_right(int **working_array, int pos, int *entry, int size)
{
	int	i;
	int	max_size;
	int	visible_towers;

	i = size - 1;
	max_size = 0;
	visible_towers = 0;
	if (pos % size == size - 1)
	{
		while (i >= 0)
		{
			if (working_array[pos / size][i] > max_size)
			{
				max_size = working_array[pos / size][i];
				visible_towers++;
			}
			i--;
		}
		if (entry[(size * 3) + pos / size] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_col_down(int **working_array, int pos, int *entry, int size)
{
	int	i;
	int	max;
	int	visible_towers;

	i = size - 1;
	max = 0;
	visible_towers = 0;
	if (pos / size == size - 1)
	{
		while (i >= 0)
		{
			if (working_array[i][pos % size] > max)
			{
				max = working_array[i][pos % size];
				visible_towers++;
			}
			i--;
		}
		if (entry[size + pos % size] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_row_left(int **working_array, int pos, int *entry, int size)
{
	int	i;
	int	max;
	int	visible_towers;

	i = 0;
	max = 0;
	visible_towers = 0;
	if (pos % size == size - 1)
	{
		while (i < size)
		{
			if (working_array[pos / size][i] > max)
			{
				max = working_array[pos / size][i];
				visible_towers++;
			}
			i++;
		}
		if (entry[(size * 2) + pos / size] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_case(int **working_array, int pos, int *entry, int size)
{
	if (check_row_left(working_array, pos, entry, size) == 1)
		return (1);
	if (check_row_right(working_array, pos, entry, size) == 1)
		return (1);
	if (check_col_down(working_array, pos, entry, size) == 1)
		return (1);
	if (check_col_up(working_array, pos, entry, size) == 1)
		return (1);
	return (0);
}
