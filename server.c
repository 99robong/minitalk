/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:35:26 by junshin           #+#    #+#             */
/*   Updated: 2021/11/27 01:21:11 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>
#include <stdio.h>

int	calcLen(int ascii, int num)
{
	if (ascii == 5)
	{
		if (num >= 240)
			return (4);
		else if (num >= 224)
			return (3);
		else if (num >= 192)
			return (2);
	}
	return (1);
}

void	endLine(int id)
{
	write(1, "\n", 1);
	kill(id, SIGUSR1);
}

void	handler(int signo, siginfo_t *info, void *context)
{
	static int		num;
	static int		ascii;
	static int		len;

	(void)info;
	(void)context;
	len = 1;
	if (ascii < 8 * len)
	{
		num = num << 1;
		if (signo == SIGUSR1)
			num = num | 1;
		len = calcLen(ascii, num);
		ascii++;
	}
	if (ascii >= 8 * len)
	{
		if (num != 255)
			write(1, &num, len);
		else
			endLine(info->si_pid);
		num = 0;
		ascii = 0;
	}
	return ;
}

int	main(void)
{
	struct sigaction	sigact;
	int					pid;
	char				*pid_str;

	pid = getpid();
	pid_str = ft_itoa(pid);
	sigact.sa_sigaction = handler;
	sigact.sa_flags = SA_SIGINFO;
	write(1, pid_str, ft_strlen(pid_str));
	write(1, "\n", 1);
	free(pid_str);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		;
	return (0);
}
