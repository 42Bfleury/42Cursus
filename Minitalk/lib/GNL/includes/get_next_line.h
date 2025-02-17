/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:06:04 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/15 17:36:21 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);

int			ft_gnl_strlen(char *str);
char		*ft_gnl_strchr(char *str, int c);
char		*ft_gnl_strdup(char *str, int len);
char		*ft_gnl_strjoin(char *str1, char *str2);
#endif
