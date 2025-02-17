/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:40:48 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/15 21:15:06 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	_move_rr(int n, t_list **s, t_list **d, char p)
{
	int	i;
	int	moves_s;
	int	moves_d;

	i = 0;
	moves_s = ps_get_moves(*s, ps_get_pos(*s, n), 0);
	moves_d = ps_get_moves(*d, ps_get_new_pos(*d, n, (p == 1)), 0);
	while (i < moves_s && i < moves_d)
	{
		ps_rr(s, d);
		i++;
	}
	while (i < moves_s--)
		ps_rotate(s, -p);
	while (i < moves_d--)
		ps_rotate(d, p);
}

static void	_move_rrr(int n, t_list **s, t_list **d, char p)
{
	int	i;
	int	moves_s;
	int	moves_d;

	i = 0;
	moves_s = ps_get_moves(*s, ps_get_pos(*s, n), 0);
	moves_d = ps_get_moves(*d, ps_get_new_pos(*d, n, (p == 1)), 0);
	while (i > moves_s && i > moves_d)
	{
		ps_rrr(s, d);
		i--;
	}
	while (i > moves_s++)
		ps_rev_rotate(s, -p);
	while (i > moves_d++)
		ps_rev_rotate(d, p);
}

static void	_move_rr_r(int n, t_list **s, t_list **d, char p)
{
	int	moves_s;
	int	moves_d;

	moves_s = ps_get_moves(*s, ps_get_pos(*s, n), 0);
	moves_d = ps_get_moves(*d, ps_get_new_pos(*d, n, (p == 1)), 0);
	while (moves_s++)
		ps_rev_rotate(s, -p);
	while (moves_d--)
		ps_rotate(d, p);
}

static void	_move_r_rr(int n, t_list **s, t_list **d, char p)
{
	int	moves_s;
	int	moves_d;

	moves_s = ps_get_moves(*s, ps_get_pos(*s, n), 0);
	moves_d = ps_get_moves(*d, ps_get_new_pos(*d, n, (p == 1)), 0);
	while (moves_s--)
		ps_rotate(s, -p);
	while (moves_d++)
		ps_rev_rotate(d, p);
}

void	ps_move(int n, t_list **s, t_list **d, char p)
{
	int	moves_s;
	int	moves_d;

	moves_s = ps_get_moves(*s, ps_get_pos(*s, n), 0);
	moves_d = ps_get_moves(*d, ps_get_new_pos(*d, n, (p == 1)), 0);
	if (moves_s >= 0 && moves_d >= 0)
		_move_rr(n, s, d, p);
	else if (moves_s <= 0 && moves_d <= 0)
		_move_rrr(n, s, d, p);
	else if (moves_s <= 0 && moves_d >= 0)
		_move_rr_r(n, s, d, p);
	else if (moves_s >= 0 && moves_d <= 0)
		_move_r_rr(n, s, d, p);
}
