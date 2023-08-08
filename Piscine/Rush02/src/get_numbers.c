/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smohasse <smohasse@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:43:35 by smohasse          #+#    #+#             */
/*   Updated: 2023/08/06 18:43:39 by smohasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct entry
{
	long		number;
	char		*word;
}	t_entry;
long		ft_atoi(const char *str);
void		ft_putstr(char *str);
t_entry		*convert_dictionary(char *file, long *line_count);

long	getdec(long number)
{
	if (number >= 90)
		return (90);
	else if (number >= 80)
		return (80);
	else if (number >= 70)
		return (70);
	else if (number >= 60)
		return (60);
	else if (number >= 50)
		return (50);
	else if (number >= 40)
		return (40);
	else if (number >= 30)
		return (30);
	else if (number >= 20)
		return (20);
	else if (number <= 20)
		return (number);
	else
		return (0);
}

long	getmult(long number)
{
	if (number >= 1000000000)
		return (1000000000);
	else if (number >= 1000000)
		return (1000000);
	else if (number >= 1000)
		return (1000);
	else if (number >= 100)
		return (100);
	else
		return (getdec(number));
}

void	print_words(long n, t_entry *dictionary, long *is_first)
{
	long	i;
	long	mult;

	i = 0;
	mult = getmult(n);
	if (mult >= 100)
		print_words(n / mult, dictionary, is_first);
	if (*is_first == 0)
		write(1, " ", 1);
	*is_first = 0;
	while (dictionary[i].number != mult)
		i++;
	ft_putstr(dictionary[i].word);
	if (mult != 0 && n % mult != 0)
		print_words(n % mult, dictionary, is_first);
}
