/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viewgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:56:22 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/30 21:56:02 by prchught         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ourFunctions.h"

void	freegrid(int **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	get_gridnum(int *num)
{
	int	i;
	int	count;

	i = 0;
	while (num[i])
	{
		i++;
	}
	count = i / 4;
	return (count);
}

void	*stoi(char *str, int *view)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			view[count] = str[i] - '0';
			count++;
		}
		i++;
	}
	return (0);
}
