/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 01:43:32 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/16 23:03:32 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	print_debug(char *name, int value)
{
	int	i;

	i = 32;
	ft_printf("(");
	while (i--)
		ft_printf("%i", (value >> i & 1));
	ft_printf(") - [%s: %i]\n", name, value);
}
