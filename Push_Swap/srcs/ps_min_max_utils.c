/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_min_max_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:59:27 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 15:42:52 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_find_min(t_list *l)
{
	int		min;

	if (!l)
		return (0);
	min = (int)(long)l->content;
	while (l)
	{
		if ((int)(long)l->content < min)
			min = (int)(long)l->content;
		l = l->next;
	}
	return (min);
}

int	ps_find_max(t_list *l)
{
	int		max;

	if (!l)
		return (0);
	max = (int)(long)l->content;
	while (l)
	{
		if ((int)(long)l->content > max)
			max = (int)(long)l->content;
		l = l->next;
	}
	return (max);
}

int	ps_find_pos_min(t_list *l)
{
	int		pos;
	int		min;
	int		result;

	pos = 0;
	result = 0;
	min = (int)(long)l->content;
	while (l)
	{
		pos++;
		if (!result || (int)(long)l->content < min)
		{
			min = (int)(long)l->content;
			result = pos;
		}
		l = l->next;
	}
	return (result);
}

int	ps_find_pos_max(t_list *l)
{
	int		pos;
	int		max;
	int		result;

	pos = 0;
	result = 0;
	max = (int)(long)l->content;
	while (l)
	{
		pos++;
		if (!result || (int)(long)l->content > max)
		{
			max = (int)(long)l->content;
			result = pos;
		}
		l = l->next;
	}
	return (result);
}
