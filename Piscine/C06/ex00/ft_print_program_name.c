/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:16:07 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/05 13:16:08 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*program_name;

	if (argc >= 1)
	{
		program_name = argv[0];
		while (*program_name)
		{
			write(1, program_name, 1);
			program_name++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
