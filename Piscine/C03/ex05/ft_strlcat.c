/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:53:00 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/26 12:53:01 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	total_len;
	unsigned int	copied_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	total_len = dest_len + src_len;
	copied_len = 0;
	if (size <= dest_len)
		return (size + src_len);
	while (*dest)
		dest++;
	while (*src && copied_len < (size - dest_len - 1))
	{
		*dest++ = *src++;
		copied_len++;
	}
	*dest = '\0';
	return (total_len);
}
/*
#include <stdio.h>
int	main(void)
{
	char	des[] = " my darling!";
	char    src[20] = "Hallo";

	printf("This ist the Src: %s\n", src);
	printf("This ist the Str: %s\n", des);
	int *result = ft_strlcat(des, src, 20);
	printf("This ist the Result: %d\n", result);
}*/
