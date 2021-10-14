/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:45:01 by junshin           #+#    #+#             */
/*   Updated: 2021/10/15 00:19:14 by junshin          ###   ########.fr       */
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

	bit = 0;
	while (str)
	{
		if (!strlen(str))
			return ;
		bit = 128;
		while (bit)
		{
			if (bit & *str)
				kill(atoi(pid), SIGUSR1);
			else
				kill(atoi(pid), SIGUSR2);
			bit = bit >> 1;
			usleep(100);
		}
		str++;
	}
	bit = 8;
	while (bit--)
		kill(atoi(pid), SIGUSR1);
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc < 3)
		printf("Usage : ./%s PID \n", argv[0]);
	else
		sigtest(argv[1], argv[2]);
	return (0);
}
