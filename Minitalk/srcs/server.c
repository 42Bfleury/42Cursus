/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:11:49 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/17 11:43:58 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int		g_c_pid = 0;

int	receive_int(int signal)
{
	static int	i = 0;
	static int	result = 0;

	if (i == 32)
	{
		result = 0;
		i = 0;
	}
	i++;
	result <<= 1;
	if (signal == SIGUSR2)
		result++;
	if (g_c_pid)
		kill(g_c_pid, SIGUSR1);
	if (i == 32)
		return (result);
	return (0);
}

int	convert_bits(int signal, char **str)
{
	static int	i = 0;
	static char	c = 0;

	if (i < 8)
	{
		c <<= 1;
		if (signal == SIGUSR2)
			c++;
		i++;
	}
	if (i == 8)
	{
		i = 0;
		(*str)[ft_strlen(*str)] = c;
		if (!c)
			return (1);
		c = 0;
	}
	return (0);
}

int	receive_message(int signal, int size)
{
	static char	*str = NULL;

	if (!str)
	{
		str = ft_calloc(size + 1, sizeof(*str));
		if (!str)
			exit(ft_printf(RED"(Server)[Error]: \
				Failed memory allocation...\n"E));
	}
	if (convert_bits(signal, &str))
	{
		ft_printf(G"(Client)"Y"[PID %i]: "E, g_c_pid);
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
		kill(g_c_pid, SIGUSR1);
		usleep(SLEEP_TIME);
		kill(g_c_pid, SIGUSR2);
		ft_printf(G"(Server)"Y"[PID %i]:"E" Waiting for a message...\n",
			getpid());
		return (1);
	}
	kill(g_c_pid, SIGUSR1);
	return (0);
}

void	signal_handler(int signal)
{
	static int		bits = 0;
	static int		message_size = 0;

	if (signal == SIGINT)
		exit((ft_printf(G"\n(Server)"Y"[PID %i]:"E" "RED"Exiting...\n"E,
					getpid()) && 0) || 0);
	if (++bits <= 64)
	{
		if (bits <= 32)
			g_c_pid = receive_int(signal);
		else
			message_size = receive_int(signal);
		if (MINITALK_DEBUG && bits == 64)
		{
			print_debug("Client PID", g_c_pid);
			print_debug("Message size", message_size);
		}
	}
	else if (receive_message(signal, message_size))
	{
		bits = 0;
		message_size = 0;
		g_c_pid = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = signal_handler;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf(G"(Server)"Y"[PID %i]:"E" Waiting for a message...\n", getpid());
	while (1)
		continue ;
	return (0);
}
