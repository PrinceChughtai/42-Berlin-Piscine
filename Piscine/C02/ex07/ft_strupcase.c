/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:40:12 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/25 10:40:21 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
    int result = 0;
	char	src[] = "Wazz upppp?";

	printf("This ist the Src: %s\n", src);
	result = ft_strlen(src);
	printf("This ist the Result: %d\n", result);
}*/
