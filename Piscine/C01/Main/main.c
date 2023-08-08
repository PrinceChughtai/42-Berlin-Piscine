/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:08:40 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/24 15:08:43 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int main()
{
	int n = 13;
	int *nbr8 = &n;
	int **nbr7 = &nbr8;
	int ***nbr6 = &nbr7;
	int ****nbr5 = &nbr6;
	int *****nbr4 = &nbr5;
	int ******nbr3 = &nbr4;
	int *******nbr2 = &nbr3;
	int ********nbr1 = &nbr2;
	int *********nbr = &nbr1;

	ft_ultimate_ft(nbr);
	
	printf("n = %d\n", n);
	
	return(0);
}

#include <stdio.h>
int main()
{
	int	a;
	int	b;
	
	a = 10;
	b = 5;
	printf("%d, %d\n", a, b);
	ft_swap(&a, &b);
	printf("%d, %d\n", a, b);
	return (0);
}

#include <stdio.h>
int main()
{
	int a;
	int b;
	int div;
	int mod;

	a = 12;
	b = 3;
	div = 0;
	mod = 0;
	ft_div_mod(a, b, &div, &mod);
	printf("%d\n%d\n", div, mod);
	return (0);
}

#include <stdio.h>
int main()
{
	int a;
	int b;

	a = 20;
	b = 7;
	printf("a %d b %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("div %d mod %d\n", a, b);
	return (0);
}

int main()
{
	ft_putstr("Lets goooo!\n");
	return (0);
}

#include <stdio.h>
int main()
{
	printf("%d\n", ft_strlen("Hello my Friend"));
	return (0);
}

#include <stdio.h>
int main()
{
	int tab[6] = {0, 1, 2, 3, 4, 5};
	int size = 6;

	ft_rev_int_tab(tab, size);
	printf("%d", tab);
	return (0);
}

#include <stdio.h>
int main(void)
{
	int tab[7] = {8, 3, 5, 2, 1, 7, 9};
	int size = 7;

	ft_sort_int_tab(tab, size);
	printf("%d", tab);
	return (0);
}
