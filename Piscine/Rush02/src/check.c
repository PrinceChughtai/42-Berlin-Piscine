/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smohasse <smohasse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:33:12 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/06 19:37:23 by smohasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct entry{
	long	number;
	char	*word;
}	t_entry;
long	ft_atoi(const char *str);

int	is_valid_number(const char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	if (c > 20)
		return (0);
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_dictionary_file(const char *filename)
{
	long	fd;
	char	buffer[1];
	long	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	bytes_read = read(fd, buffer, 1);
	close(fd);
	if (bytes_read == -1)
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}
