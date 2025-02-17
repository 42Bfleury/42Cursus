/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:11:41 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/08 15:06:11 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	_print_format(va_list args, const char format)
{
	int	printed_chars;

	printed_chars = 0;
	if (format == '%')
		printed_chars += _print_char('%');
	else if (format == 'c')
		printed_chars += _print_char(va_arg(args, int));
	else if (format == 's')
		printed_chars += _print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		printed_chars += _print_integer(va_arg(args, int));
	else if (format == 'u')
		printed_chars += _print_unsigned_integer(va_arg(args, unsigned int));
	else if (format == 'p')
		printed_chars += _print_pointer(va_arg(args, unsigned long long));
	else if (format == 'x')
		printed_chars += _print_hexa_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		printed_chars += _print_hexa_upper(va_arg(args, unsigned int));
	return (printed_chars);
}

static int	_is_format(char c)
{
	int	flag;

	flag = 0;
	if (c == '%' || c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'p' || c == 'x' || c == 'X')
		flag = 1;
	return (flag);
}

static int	_is_alpha(char c)
{
	int	flag;

	flag = 0;
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		flag = 1;
	return (flag);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			printed_chars;
	va_list		args;

	i = 0;
	printed_chars = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && _is_format(str[i + 1]))
		{
			i++;
			printed_chars += _print_format(args, str[i]);
		}
		else if (str[i] == '%' && !_is_alpha(str[i + 1])
			&& !_is_format(str[i + 1]))
			return (-1);
		else
			printed_chars += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (printed_chars);
}
