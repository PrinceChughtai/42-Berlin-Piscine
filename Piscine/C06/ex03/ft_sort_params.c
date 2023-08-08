/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:16:57 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/05 13:16:58 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_args(char **args, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - i)
		{
			if (ft_strcmp(args[j], args[j + 1]) > 0)
			{
				temp = args[j];
				args[j] = args[j + 1];
				args[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*arg;
	int		i;

	i = 1;
	ft_sort_args(argv, argc);
	while (i < argc)
	{
		arg = argv[i];
		while (*arg)
		{
			write(1, arg, 1);
			arg++;
		}
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
