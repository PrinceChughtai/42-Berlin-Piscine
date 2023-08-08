/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:45:27 by pchughta          #+#    #+#             */
/*   Updated: 2023/08/06 14:45:29 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct entry
{
	long	number;
	char	*word;
}	t_entry;

char	*ft_strdup(char *src)
{
	long	i;
	long	len;
	char	*duplicate;

	len = 0;
	while (src[len] != '\0')
		len++;
	duplicate = (char *)malloc(sizeof(char) * (len + 1));
	if (!duplicate)
		return (0);
	i = 0;
	while (i < len)
	{
		duplicate[i] = src[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

long	ft_atoi(const char *str)
{
	long	res;
	long	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

void	ft_putstr(char *str)
{
	long	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
