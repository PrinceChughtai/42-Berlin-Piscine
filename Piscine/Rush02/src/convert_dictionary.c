/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dictionary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:46:03 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/06 14:46:04 by pchughta         ###   ########.fr       */
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
void	conversion(long *line_count, t_entry *dictionary, long fd, char *c);
char	*print_malloc_error(void);
char	*re_malloc(unsigned long i, char *str, unsigned long str_size);
char	*free_string(char *str);
char	*trim_spaces(char str[]);

char	*copy_numbers(long fd, char *str, unsigned long str_size)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			continue ;
		if (c >= '0' && c <= '9')
		{
			str[i] = c;
			if (i == str_size)
				str = re_malloc(i, str, str_size);
			if (i == str_size)
				str_size *= 2;
			i++;
		}
		else
			break ;
	}
	if (i == 0)
		return (free_string(str));
	str[i] = '\0';
	return (str);
}

char	*find_number(long fd)
{
	char			*str;
	unsigned long	str_size;

	str = NULL;
	str_size = 16;
	str = malloc(sizeof(char) * str_size);
	if (str == NULL)
		return (print_malloc_error());
	str = copy_numbers(fd, str, str_size);
	return (str);
}

char	*copy_words(long fd, char *c, char *str, unsigned long str_size)
{
	unsigned int	i;

	i = 0;
	while (c[0] != '\n')
	{
		if (i == str_size)
			str = re_malloc(i, str, str_size);
		if (i == str_size)
			str_size *= 2;
		str[i] = c[0];
		if (read(fd, c, 1) <= 0)
			break ;
		i++;
	}
	if (i == 0)
		return (free_string(str));
	str[i] = '\0';
	return (str);
}

char	*find_word(long fd, char *c)
{
	char			*str;
	unsigned long	str_size;

	str = NULL;
	str_size = 16;
	str = malloc(sizeof(char) * str_size);
	if (str == NULL)
		return (print_malloc_error());
	str = copy_words(fd, c, str, str_size);
	str = trim_spaces(str);
	return (str);
}

t_entry	*convert_dictionary(char *file, long *line_count)
{
	long		fd;
	char		c[1];
	t_entry		*dictionary;

	dictionary = NULL;
	fd = open(file, O_RDONLY);
	if (check_fd(fd) == 0)
		return (NULL);
	*line_count = 0;
	while (read(fd, c, 1) > 0)
		if (c[0] == '\n')
			(*line_count)++;
	dictionary = malloc(sizeof(t_entry) * (*line_count));
	if (check_fd_null(dictionary, fd) == 0)
		return (NULL);
	close(fd);
	fd = open(file, O_RDONLY);
	if (check_fd2(dictionary, fd) == 0)
		return (NULL);
	conversion(line_count, dictionary, fd, c);
	close(fd);
	return (dictionary);
}
