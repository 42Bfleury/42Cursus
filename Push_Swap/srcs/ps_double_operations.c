/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_double_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:18:59 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 15:15:46 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_ss(t_list **a, t_list **b)
{
	ps_swap(a, 0);
	ps_swap(b, 0);
	ft_printf("ss\n");
}

void	ps_rr(t_list **a, t_list **b)
{
	ps_rotate(a, 0);
	ps_rotate(b, 0);
	ft_printf("rr\n");
}

void	ps_rrr(t_list **a, t_list **b)
{
	ps_rev_rotate(a, 0);
	ps_rev_rotate(b, 0);
	ft_printf("rrr\n");
}
