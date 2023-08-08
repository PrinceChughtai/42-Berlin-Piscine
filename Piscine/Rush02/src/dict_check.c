/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:29:10 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/06 20:29:11 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct dictentry{
	long	number;
	char	*word;
}	t_entry;
long	ft_atoi(const char *str);
char	*ft_strdup(char *src);
int		check_fd(long fd);
int		check_fd_null(t_entry *dictionary, long fd);
int		check_fd2(t_entry *dictionary, long fd);
char	*find_number(long fd);
char	*find_word(long fd, char *c);

int	check_fd(long fd)
{
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

int	check_fd_null(t_entry *dictionary, long fd)
{
	if (dictionary == NULL)
	{
		write(1, "Malloc Error\n", 13);
		close(fd);
		return (0);
	}
	return (1);
}

int	check_fd2(t_entry *dictionary, long fd)
{
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		free(dictionary);
		return (0);
	}
	return (1);
}

void	conversion(long *line_count, t_entry *dictionary, long fd, char *c)
{
	long	i;
	char	*tmp;

	i = 0;
	while (i < *line_count)
	{
		dictionary[i].number = ft_atoi(find_number(fd));
		read(fd, c, 1);
		while (c[0] == ' ')
			read(fd, c, 1);
		if (c[0] == ':')
			read(fd, c, 1);
		while (c[0] == ' ')
			read(fd, c, 1);
		tmp = find_word(fd, c);
		dictionary[i].word = ft_strdup(tmp);
		free(tmp);
		i++;
	}
}
