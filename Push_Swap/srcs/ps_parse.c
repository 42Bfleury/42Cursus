/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 03:53:20 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/13 12:41:08 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	_atol(const char *str)
{
	int		i;
	long	result;
	int		negative;

	i = 0;
	result = 0;
	negative = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			negative = 1;
	while (ft_isdigit(str[i]))
		result = (result * 10) + (str[i++] - '0');
	if (negative)
		return (-result);
	return (result);
}

static int	_parse_arg(t_list **l, char *s)
{
	int		i;
	long	n;
	t_list	*new;

	i = 0;
	if (s && (s[i] == '-' || s[i] == '+'))
		i++;
	if (!s || !s[i])
		return (ps_error(l, NULL, 0));
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (ps_error(l, NULL, 0));
		i++;
	}
	n = _atol(s);
	if (n < INT_MIN || n > INT_MAX)
		return (ps_error(l, NULL, 0));
	new = ft_lstnew((void *)n);
	if (!new)
		return (ps_error(l, NULL, 0));
	ft_lstadd_back(l, new);
	if (!*l)
		return (ps_error(l, NULL, 0));
	return (1);
}

static int	_parse_string(t_list **l, char *s)
{
	int		i;
	int		result;
	char	**tab;

	i = 0;
	result = 1;
	tab = ft_split(s, ' ');
	if (!tab)
		return (ps_error(l, NULL, 0));
	while (tab[i])
	{
		if (result)
			result = _parse_arg(l, tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (result);
}

t_list	*ps_parse(int ac, char **av)
{
	int		i;
	int		result;
	t_list	*a;

	a = NULL;
	i = 1;
	result = 1;
	while (result && i < ac)
	{
		if (!ft_strlen(av[i]))
			result = ps_error(&a, NULL, 0);
		else if (ft_strchr(av[i], ' '))
			result = _parse_string(&a, av[i]);
		else
			result = _parse_arg(&a, av[i]);
		i++;
	}
	if (!result)
		return (NULL);
	return (a);
}
