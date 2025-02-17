/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:44:53 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 15:37:01 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_get_pos(t_list *l, int n)
{
	int	pos;

	pos = 0;
	while (l)
	{
		pos++;
		if (n == (int)(long)l->content)
			return (pos);
		l = l->next;
	}
	return (0);
}

int	ps_get_new_pos(t_list *l, int n, int asc)
{
	int		i;
	int		min;
	int		max;
	int		prev;
	int		next;

	i = 1;
	min = ps_find_min(l);
	max = ps_find_max(l);
	while (l)
	{
		i++;
		if (!l->next)
			return (1);
		prev = (int)(long)l->content;
		next = (int)(long)l->next->content;
		if ((asc && prev < n && n < next)
			|| (asc && (n < min || max < n) && prev == max && next == min)
			|| (!asc && prev > n && n > next)
			|| (!asc && (n < min || max < n) && prev == min && next == max))
			break ;
		l = l->next;
	}
	return (i);
}

int	ps_get_moves(t_list *l, int pos, int src)
{
	int		size;

	if (src)
		size = ft_lstsize(l) + pos - 1;
	else
		size = ft_lstsize(l);
	if (pos > (size / 2) + 1)
		return ((size - pos + 1) * -1);
	return (pos - 1);
}

int	ps_get_nb_op(t_list *s, t_list *d, int pos_s, int pos_d)
{
	int		moves_s;
	int		moves_d;

	moves_s = ps_get_moves(s, pos_s, 1);
	moves_d = ps_get_moves(d, pos_d, 0);
	if (moves_s >= 0 && moves_d >= 0)
	{
		if (moves_s < moves_d)
			return (moves_d + 1);
		return (moves_s + 1);
	}
	if (moves_s <= 0 && moves_d <= 0)
	{
		if (moves_s < moves_d)
			return (-moves_s + 1);
		return (-moves_d + 1);
	}
	if (moves_s <= 0)
		return (-moves_s + moves_d + 1);
	return (-moves_d + moves_s + 1);
}

int	ps_get_cheapest(t_list *s, t_list *d, int asc)
{
	int	tmp;
	int	pos;
	int	moves;
	int	result;
	int	new_pos;

	pos = 1;
	result = (int)(long)s->content;
	new_pos = ps_get_new_pos(d, result, asc);
	moves = ps_get_nb_op(s, d, pos, new_pos);
	while (s)
	{
		new_pos = ps_get_new_pos(d, (int)(long)s->content, asc);
		tmp = ps_get_nb_op(s, d, pos, new_pos);
		if (tmp < moves)
		{
			moves = tmp;
			result = (int)(long)s->content;
		}
		s = s->next;
		pos++;
	}
	return (result);
}
