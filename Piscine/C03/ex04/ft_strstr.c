/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:48:29 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/26 12:48:33 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*s1;
	char	*s2;

	s1 = str;
	s2 = to_find;
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		s1 = str;
		s2 = to_find;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return (str);
		str++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	src[] = "Hallo my darling!";
	char    des[] = "Hallo ";

	printf("This ist the Search: %s\n", des);
	printf("This ist the Str: %s\n", src);
	char *result = ft_strstr(src, des);
	printf("This ist the Result: %s\n", result);
}*/
