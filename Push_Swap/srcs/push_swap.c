/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:27:53 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/13 12:39:14 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_error(t_list **a, t_list **b, int p)
{
	ft_lstclear(a, NULL);
	ft_lstclear(b, NULL);
	if (p)
		ft_putstr_fd("Error\n", 2);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (-1);
	a = ps_parse(ac, av);
	b = NULL;
	if (!a)
		return (ps_error(&a, &b, 1));
	if (ps_check_dup(a))
		return (ps_error(&a, &b, 1));
	if (!ps_check_sorted(a))
		ps_sort(&a, &b);
	ps_reorder(&a, 1);
	ft_lstclear(&a, NULL);
	return (0);
}
