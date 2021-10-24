/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:35:26 by junshin           #+#    #+#             */
/*   Updated: 2021/10/24 20:53:25 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

void	handler(int signo, siginfo_t *info, void *context)
{
	static int		num;
	static int		ascii;

	(void)info;
	(void)context;
	if (ascii < 8)
	{
		num = num << 1;
		if (signo == SIGUSR1)
			num = num | 1;
		ascii++;
	}
	if (ascii >= 8)
	{
		if (num < 255)
			write(1, &num, 1);
		if (num == 255)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
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
