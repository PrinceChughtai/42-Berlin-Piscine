/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:38:13 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/26 12:38:15 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*result;

	result = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char	src[] = "my darling!";
	char    des[] = "Hallo ";

	printf("This ist the Src: %s\n", src);
	printf("This ist the Des: %s\n", des);
	char *result = ft_strcat(des, src);
	printf("This ist the Result: %s\n", result);
}*/
