/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchughta <pchughta@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:20:26 by pchughta          #+#    #+#             */
/*   Updated: 2023/07/26 13:20:27 by pchughta         ###   ########.fr       */
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

int ft_power(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        result *= base;
        exponent--;
    }
    return result;
}

int ft_atoi_base(char *str, char *base) {
    int base_len = ft_strlen(base);
    int str_len = ft_strlen(str);
    int sign = 1;
    int result = 0;

    if (!is_valid_base(base))
        return 0;

    // Handle optional sign
    if (*str == '+' || *str == '-') {
        sign = (*str == '-') ? -1 : 1;
        str++;
        str_len--;
    }

    // Convert the string to the integer representation
    for (int i = 0; i < str_len; i++) {
        int digit_value = -1;
        for (int j = 0; j < base_len; j++) {
            if (str[i] == base[j]) {
                digit_value = j;
                break;
            }
        }
        if (digit_value == -1) {
            // Invalid character in the input string
            return 0;
        }
        result += digit_value * ft_power(base_len, str_len - i - 1);
    }

    return result * sign;
}

// Example usage:
int main() {
    int result = ft_atoi_base("1010", "01");
    char buffer[20];
    int buffer_len = snprintf(buffer, sizeof(buffer), "%d", result);
    write(1, buffer, buffer_len);
    return 0;
}

