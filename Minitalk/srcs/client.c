/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:11:28 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/17 12:04:59 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int		g_s_pid = 0;

void	send_int(pid_t serv_pid, int value, char *name, int lock)
{
	int	i;

	i = 32;
	if (MINITALK_DEBUG)
		print_debug(name, value);
	while (i--)
	{
		if (lock)
			g_s_pid = -g_s_pid;
		if (value & (1 << i))
			kill(serv_pid, SIGUSR2);
		else
			kill(serv_pid, SIGUSR1);
		if (!lock)
			usleep(SLEEP_TIME);
		else
		{
			while (g_s_pid < 0)
				continue ;
		}
	}
}

void	send_message(int pid, char *message)
{
	int				i;

	while (*message)
	{
		i = 8;
		while (i--)
		{
			g_s_pid = -g_s_pid;
			if (*message & (1 << i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (g_s_pid < 0)
				continue ;
		}
		message++;
	}
	i = 8;
	while (i--)
	{
		g_s_pid = -g_s_pid;
		kill(pid, SIGUSR1);
		while (g_s_pid < 0)
			continue ;
	}
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_s_pid = -g_s_pid;
	else if (signal == SIGUSR2)
	{
		ft_printf(G"(Server)"Y"[PID %i]:"E" Message successfully received!\n",
			g_s_pid);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf(G"(Client)"Y"[PID %i]: "RED"Wrong number of arguments!\n",
			getpid());
		return (-1);
	}
	g_s_pid = ft_atoi(av[1]);
	if (g_s_pid <= 0 || kill(g_s_pid, 0) == -1)
	{
		ft_printf(G"(Client)"Y"[PID %i]: "RED"Wrong PID!\n", getpid());
		return (-1);
	}
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	if (MINITALK_DEBUG)
		ft_printf(G"(Client)"Y"[PID %i]: "E"%s\n", getpid(), av[2]);
	ft_printf(G"(Client)"Y"[PID %i]: "E"Sending message...\n", getpid(), av[2]);
	send_int(g_s_pid, getpid(), "Client PID", 0);
	send_int(g_s_pid, ft_strlen(av[2]), "Message size", 1);
	send_message(g_s_pid, av[2]);
	pause();
	return (0);
}
