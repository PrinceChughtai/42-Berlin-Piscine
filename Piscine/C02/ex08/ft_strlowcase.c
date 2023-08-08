/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:54:38 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/25 10:54:40 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	src[] = "HaLLo" ;
//	char    des[20];
	printf("This ist the Src: %s\n", src);
	char *result = ft_strlowcase(src);
	printf("This ist the Result: %s\n", result);
	
}*/
