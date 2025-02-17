/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:28:53 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/15 21:09:02 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../lib/includes/libftfull.h"

int		ps_error(t_list **a, t_list **b, int p);

t_list	*ps_parse(int ac, char **av);

int		ps_check_dup(t_list *l);
int		ps_check_sorted(t_list *l);

int		ps_find_min(t_list *l);
int		ps_find_max(t_list *l);
int		ps_find_pos_min(t_list *l);
int		ps_find_pos_max(t_list *l);

int		ps_get_pos(t_list *l, int n);
int		ps_get_moves(t_list *l, int pos, int src);
int		ps_get_new_pos(t_list *l, int n, int asc);
int		ps_get_cheapest(t_list *s, t_list *d, int asc);
int		ps_get_nb_op(t_list *s, t_list *d, int pos_s, int pos_d);

void	ps_sort(t_list **a, t_list **b);
void	ps_reorder(t_list **l, int p);

void	ps_swap(t_list **l, char p);
void	ps_rotate(t_list **l, char p);
void	ps_rev_rotate(t_list **l, char p);
void	ps_push(t_list **s, t_list **d, char p);

void	ps_ss(t_list **a, t_list **b);
void	ps_rr(t_list **a, t_list **b);
void	ps_rrr(t_list **a, t_list **b);

void	ps_move(int n, t_list **s, t_list **d, char p);

#endif
