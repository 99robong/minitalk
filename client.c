/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:45:01 by junshin           #+#    #+#             */
/*   Updated: 2021/10/24 00:33:26 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void	sigtest(char *pid, char *str)
{
	int	bit;
	int	id;

	id = atoi(pid);
	while (str && strlen(str))
	{
		bit = 128;
		while (bit)
		{
			if (bit & *str)
				kill(id, SIGUSR1);
			else
				kill(id, SIGUSR2);
			bit = bit >> 1;
			usleep(100);
		}
		str++;
	}
	bit = 8;
	while (bit--)
	{
		kill(id, SIGUSR1);
		usleep(100);
	}
	return ;
}

void	success_ack(int signo)
{
	(void)signo;
	write(1, "ACK SUCCESS!!\n", 14);
	exit(0);
}

int	main(int argc, char *argv[])
{
	signal(SIGUSR1, success_ack);
	if (argc != 3)
		printf("Usage : %s PID MESSAGE \n", argv[0]);
	else
		sigtest(argv[1], argv[2]);
	sleep(1);
	printf("over 1sec");
	return (0);
}
