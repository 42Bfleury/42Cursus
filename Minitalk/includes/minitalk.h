/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:07:01 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/17 11:46:30 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define MINITALK_DEBUG		0
# define SLEEP_TIME			55
# define Y					"\033[33m"
# define RED				"\033[31m"
# define G					"\033[1;32m"
# define E					"\033[0m"

# include <signal.h>
# include <sys/types.h>
# include "../lib/includes/libftfull.h"

void	print_debug(char *name, int value);
#endif