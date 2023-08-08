/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:19:15 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/26 13:19:19 by pchughta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef unsigned int uint;

int ft_strlen(char *str) {
    int len = 0;
    while (str[len])
        len++;
    return len;
}

int is_valid_base(char *base) {
    if (!base || base[0] == '\0' || base[1] == '\0')
        return 0;

    for (int i = 0; base[i]; i++) {
        if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || base[i] == '\t')
            return 0;

        for (int j = i + 1; base[j]; j++) {
            if (base[i] == base[j])
                return 0;
        }
    }
    return 1;
}

void ft_putnbr_base_recursive(uint nbr, char *base, uint base_len) {
    if (nbr >= base_len)
        ft_putnbr_base_recursive(nbr / base_len, base, base_len);

    char digit = base[nbr % base_len];
    write(1, &digit, 1);
}

void ft_putnbr_base(int nbr, char *base) {
    int base_len = ft_strlen(base);

    if (!is_valid_base(base))
        return;

    if (nbr < 0) {
        write(1, "-", 1);
        ft_putnbr_base_recursive(-nbr, base, base_len);
    } else {
        ft_putnbr_base_recursive(nbr, base, base_len);
    }
}

