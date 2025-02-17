/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:42:21 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 15:40:17 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_check_dup(t_list *l)
{
	t_list	*tmp;

	if (!l)
		return (-1);
	while (l)
	{
		tmp = l->next;
		while (tmp)
		{
			if (l->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		l = l->next;
	}
	return (0);
}

int	ps_check_sorted(t_list *l)
{
	int		nb;
	int		first;
	int		pos;
	int		pos_min;

	if (!l)
		return (0);
	pos = 0;
	pos_min = ps_find_pos_min(l);
	first = (int)(long)l->content;
	while (l)
	{
		nb = (int)(long)l->content;
		pos++;
		if ((l->next && pos != (pos_min - 1)
				&& nb > (int)(long)l->next->content)
			|| (!l->next && pos_min > 1 && first < nb))
			return (0);
		l = l->next;
	}
	return (1);
}
