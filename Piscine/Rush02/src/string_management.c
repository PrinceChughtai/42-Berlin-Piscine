/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkumm <mkumm@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:12:48 by mkumm             #+#    #+#             */
/*   Updated: 2023/08/06 22:12:55 by mkumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct dictentry{
	long	number;
	char	*word;
}	t_entry;

char	*print_malloc_error(void)
{
	write(1, "Malloc Error\n", 12);
	return (0);
}

char	*re_malloc(unsigned long i, char *str, unsigned long str_size)
{
	char			*new_str;
	unsigned long	j;

	str_size *= 2;
	new_str = malloc(sizeof(char) * str_size);
	if (new_str == NULL)
	{
		free(str);
		return (print_malloc_error());
	}
	j = 0;
	while (j < i)
	{
		new_str[j] = str[j];
		j++;
	}
	free(str);
	return (new_str);
}

char	*free_string(char *str)
{
	free(str);
	return (0);
}

char	*trim_spaces(char str[])
{
	long	i;
	long	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			j = i;
			while (str[j])
			{
				str[j] = str[j + 1];
				j++;
			}
		}
		else
			i++;
	}
	return (str);
}
