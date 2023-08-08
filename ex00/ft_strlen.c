/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:07:10 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/05 14:06:30 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

/* #include <stdio.h>
int     main(void)
{
       int result = ft_strlen("Hallo");
       printf("Then length of the String is: %d", result);
       return 0;
} */
