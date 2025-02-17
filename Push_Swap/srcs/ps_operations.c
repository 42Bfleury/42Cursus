/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:18:59 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 15:44:40 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_push(t_list **s, t_list **d, char p)
{
	t_list	*tmp;

	if (!*s)
		return ;
	tmp = (*s)->next;
	ft_lstadd_front(d, *s);
	*s = tmp;
	if (p == 1)
		ft_printf("pa\n");
	if (p == -1)
		ft_printf("pb\n");
}

void	ps_swap(t_list **lst, char p)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	if (p == 1)
		ft_printf("sa\n");
	if (p == -1)
		ft_printf("sb\n");
}

void	ps_rotate(t_list **lst, char p)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *lst;
	*lst = (*lst)->next;
	tmp->next->next = NULL;
	if (p == 1)
		ft_printf("ra\n");
	if (p == -1)
		ft_printf("rb\n");
}

void	ps_rev_rotate(t_list **lst, char p)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
	if (p == 1)
		ft_printf("rra\n");
	if (p == -1)
		ft_printf("rrb\n");
}
