/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:50:27 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 15:49:55 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	_sort_lst_3(t_list **l, int p)
{
	if (!l || !*l)
		return ;
	if (!ps_check_sorted(*l))
		ps_swap(l, p);
}

void	ps_sort(t_list **a, t_list **b)
{
	int	nb;

	while (ft_lstsize(*a) > 3)
	{
		nb = ps_get_cheapest(*a, *b, 0);
		ps_move(nb, a, b, -1);
		ps_push(a, b, -1);
	}
	_sort_lst_3(a, 1);
	while (ft_lstsize(*b))
	{
		nb = ps_get_cheapest(*b, *a, 1);
		ps_move(nb, b, a, 1);
		ps_push(b, a, 1);
	}
}

void	ps_reorder(t_list **l, int p)
{
	int		i;
	int		pos_min;
	int		size;

	pos_min = ps_find_pos_min(*l);
	size = ft_lstsize(*l);
	if (pos_min <= (size / 2) + 1)
	{
		i = pos_min - 1;
		while (i--)
			ps_rotate(l, p);
	}
	else
	{
		i = size - pos_min + 1;
		while (i--)
			ps_rev_rotate(l, p);
	}
}
