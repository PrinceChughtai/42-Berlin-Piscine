/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:44:40 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/06 23:00:39 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

typedef struct entry
{
	long		number;
	char		*word;
}	t_entry;
long		ft_atoi(const char *str);
void		ft_putstr(char *str);
t_entry		*convert_dictionary(char *file, long *line_count);
int			is_valid_number(const char *str);
int			is_valid_dictionary_file(const char *filename);
void		print_words(long n, t_entry *dictionary, long *is_first);

void	free_dictionary(t_entry *dictionary, long line_count)
{
	long	i;

	i = 0;
	while (i < line_count)
	{
		free(dictionary[i].word);
		i++;
	}
	free(dictionary);
}

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	check_required_keys(t_entry *dict)
{
	long	i;
	long counter;

	i = 0;
	counter = 1;
	while (dict[i].number != 1000000000)
	{
		if (dict[i].number >= 0 && dict[i].number <= 19)
			counter++;
		if (dict[i].number >= 20 && dict[i].number <= 100
			&& (dict[i].number % 10 == 0))
			counter++;
		if (dict[i].number == 1000 || dict[i].number == 1000000
			|| dict[i].number == 1000000000)
			counter++;
		i++;
	}
	if (counter != 32)
		return (1);
	return (0);
}

int	check_duplicate_entries(t_entry *dict)
{
	long	i;
	long	j;

	i = 0;
	while (dict[i].number != 1000000000)
	{
		j = i + 1;
		while (dict[j].number)
		{
			if (dict[j].number == dict[i].number)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dictionary(t_entry *dict)
{

	if (check_duplicate_entries(dict) == 1)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	if (check_required_keys(dict) == 1)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	return (0);
}

int	argv_handling_two(char **argv)
{
	t_entry	*dictionary;
	long	is_first;
	long	line_count;
	int		i;

	if (ft_atoi(argv[1]) < 0 || !is_valid_number(argv[1]))
		return (print_error());
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == 46)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	dictionary = convert_dictionary("numbers.dict", &line_count);
	if (check_dictionary(dictionary) == 1)
		return (0);
	is_first = 1;
	print_words(ft_atoi(argv[1]), dictionary, &is_first);
	write(1, "\n", 1);
	free_dictionary(dictionary, line_count);
	return (0);
}

int	argv_handling_three(char **argv)
{
	t_entry	*dictionary;
	long	is_first;
	long	line_count;

	if (ft_atoi(argv[1]) < 0 || !is_valid_number(argv[1]))
		return (print_error());
	if (!is_valid_dictionary_file(argv[1]))
		return (0);
	dictionary = convert_dictionary(argv[1], &line_count);
	is_first = 1;
	print_words(ft_atoi(argv[2]), dictionary, &is_first);
	write(1, "\n", 1);
	free_dictionary(dictionary, line_count);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		argv_handling_two(argv);
	else if (argc == 3)
		argv_handling_three(argv);
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
