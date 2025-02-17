/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:12:37 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/08 15:06:22 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	_print_pointer(unsigned long long pointer)
{
	int	printed_chars;

	printed_chars = 0;
	if (!pointer)
		return (write(1, "(nil)", 5));
	printed_chars += write(1, "0x", 2);
	printed_chars += _print_hexa_lower(pointer);
	return (printed_chars);
}

int	_print_hexa_lower(unsigned long long nb)
{
	char	*base_hex;
	int		printed_chars;

	printed_chars = 0;
	base_hex = "0123456789abcdef";
	if (nb >= 16)
		printed_chars += _print_hexa_lower(nb / 16);
	printed_chars += write(1, &base_hex[nb % 16], 1);
	return (printed_chars);
}

int	_print_hexa_upper(unsigned int nb)
{
	char	*base_hex;
	long	printed_chars;

	printed_chars = 0;
	base_hex = "0123456789ABCDEF";
	if (nb >= 16)
		printed_chars += _print_hexa_upper(nb / 16);
	printed_chars += write(1, &base_hex[nb % 16], 1);
	return (printed_chars);
}
