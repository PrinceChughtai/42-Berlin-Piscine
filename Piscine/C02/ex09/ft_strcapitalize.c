/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:00:35 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/25 11:18:48 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capitalize_next;

	i = 0;
	capitalize_next = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' 
				&& str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
		{
			if ((str[i] >= 'a' && str[i] <= 'z') && capitalize_next)
				str[i] = str[i] - ('a' - 'A');
			else if (('A' && str[i] <= 'Z') && !capitalize_next 
				&& !(str[i] >= '0' && str[i] <= '9'))
				str[i] = str[i] + ('a' - 'A');
			capitalize_next = 0;
		}
		else
		{
			capitalize_next = 1;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	src[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un" ;
	printf("This ist the Src: %s\n", src);
	char *result = ft_strcapitalize(src);
	printf("This ist the Result: %s\n", result);
	
}*/
