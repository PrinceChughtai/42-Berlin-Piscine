/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:09:52 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/26 12:09:53 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0 && *s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}
/*
int	main(void)
{
	char	s1[] = "Hallo my darling!";
	char    s2[] = "Was geht?";
//	char	s1[] = "Hallo my darling!";
//	char    s2[] = "Hallo my darling!";
//	char    s1[] = "Was geht?";
//	char	s2[] = "Hallo my darling!";
	printf("This ist the S1: %s\n", s1);
	printf("This ist the S2: %s\n", s2);
	int result = ft_strncmp(s1, s2, 5);
	printf("This ist the Result: %d\n", result);
}*/
