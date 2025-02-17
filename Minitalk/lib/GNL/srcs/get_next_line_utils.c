/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:08:57 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/15 20:14:00 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_gnl_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	c %= 256;
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_gnl_strdup(char *str, int len)
{
	int		i;
	char	*result;

	if (!str || !len)
		return (NULL);
	i = 0;
	result = malloc(sizeof(*result) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_gnl_strjoin(char *str1, char *str2)
{
	int		len;
	char	*result;

	len = ft_gnl_strlen(str1) + ft_gnl_strlen(str2);
	result = malloc(sizeof(*result) * (len + 1));
	if (!result)
		return (free(str1), str1 = NULL, NULL);
	int (i) = 0;
	len = 0;
	if (str1)
		while (str1[i])
			result[len++] = str1[i++];
	i = 0;
	if (str2)
		while (str2[i])
			result[len++] = str2[i++];
	result[len] = 0;
	return (free(str1), str1 = NULL, result);
}
