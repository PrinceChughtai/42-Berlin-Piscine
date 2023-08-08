/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:34:18 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/26 12:34:21 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*result;

	result = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && nb > 0)
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
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
	char *result = ft_strncat(des, src, 4);
	printf("This ist the Result: %s\n", result);
}*/
