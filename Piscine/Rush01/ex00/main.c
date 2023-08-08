/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:53:57 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/29 13:53:58 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ourFunctions.h"

int	check_double(int **working_array, int pos, int num, int size)
{
	int	i;

	i = 0;
	while (i++ <= pos / size)
		if (working_array[i][pos % size] == num)
			return (1);
	i = 0;
	while (i++ <= pos % size)
		if (working_array[pos / size][i] == num)
			return (1);
	return (0);
}

void	mal(int **working_array, int row_len)
{
	int	i;

	i = 0;
	while (i < row_len) 
	{
		working_array[i] = (int *)malloc(row_len * row_len);
		i++;
	}
}

int	space(int argc, char *argv, int *pur_view_num, int row_len)
{
	if (!pur_view_num)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (check(argv, row_len) == 1)
		return (1);
	return (0);
}

//Makes a grid 0-3 colup, 4-7 coldown, 8-11 leftrow, 12-15 rightRow 
int	main(int argc, char *argv[])
{
	int	**working_array;
	int	*pur_view_num;
	int	row_len;

	working_array = 0;
	pur_view_num = (int *)malloc(81 * 81);
	stoi(argv[1], pur_view_num);
	row_len = get_gridnum(pur_view_num);
	working_array = (int **)malloc(row_len * row_len * row_len);
	mal(working_array, row_len);
	if (space (argc, argv[1], pur_view_num, row_len) == 0)
	{
		if (solve(working_array, pur_view_num, 0, row_len) == 1)
		{
			display_solution(working_array, row_len);
		}
		else
		{
			ft_putstr("Did not find any solutions\n");
		}
	}
	free(pur_view_num);
	freegrid(working_array);
	return (0);
}
