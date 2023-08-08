/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:59:16 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/29 20:59:18 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ourFunctions.h"

int	check_clue(int i, char c)
{
	if (i % 2 == 0 && !(c >= '0' && c <= '9'))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	check_space(int i, char c)
{
	if (i % 2 == 1 && c != ' ')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	check_length(int i)
{
	i = (i - i / 2);
	if (i % 4 != 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	check_count(int i, char c)
{
	int	a;

	a = c - '0';
	if (a > i)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	check(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (check_clue(i, str[i]) == 1)
			return (1);
		if (check_space(i, str[i]) == 1)
			return (1);
		if (check_count(c, str[i]) == 1)
			return (1);
		if (str[(c * c * 2)] == ' ')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	if (check_length(i) == 1)
		return (1);
	return (0);
}
