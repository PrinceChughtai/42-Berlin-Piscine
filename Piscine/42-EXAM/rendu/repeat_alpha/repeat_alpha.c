/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:17:48 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/07 15:17:49 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int 	main(int argc, char *argv[])
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	if(argc == 2)
	{
		while(argv[1][i])
		{
			if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				count = argv[1][i] - 64;
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				count = argv[1][i] - 96;
			else
				write(1, &argv[1][i], 1);
			while(count-- > 0)
				write(1, &argv[1][i], 1);
			i++;				
		}
			
	}
	write(1, "\n", 1);
	return (0);
}
