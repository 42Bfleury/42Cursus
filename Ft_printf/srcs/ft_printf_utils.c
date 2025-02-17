/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:12:25 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/08 15:06:18 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	_print_str(char *str)
{
	int	printed_chars;

	if (str == NULL)
		return (write(1, "(null)", 6));
	printed_chars = 0;
	while (*str)
	{
		write(1, str, 1);
		printed_chars++;
		str++;
	}
	return (printed_chars);
}

int	_print_integer(int nb)
{
	int	printed_chars;

	printed_chars = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		nb = -nb;
		printed_chars += write(1, "-", 1);
	}
	if (nb > 9)
	{
		printed_chars += _print_integer(nb / 10);
		printed_chars += _print_integer(nb % 10);
	}
	else
		printed_chars += _print_char('0' + nb);
	return (printed_chars);
}

int	_print_unsigned_integer(unsigned int nb)
{
	int	printed_chars;

	printed_chars = 0;
	if (nb > 9)
	{
		printed_chars += _print_integer(nb / 10);
		printed_chars += _print_integer(nb % 10);
	}
	else
		printed_chars += _print_char('0' + nb);
	return (printed_chars);
}
