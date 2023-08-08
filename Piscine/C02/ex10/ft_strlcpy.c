/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:04:51 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/31 15:04:52 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	char	src[] = "Hallo my darling!" ;
	char    des[20];
	printf("This ist the Src: %s\n", src);
	int result = ft_strlcpy(des, src, 18);
	printf("This ist the Result: %d\n", result);
}*/
