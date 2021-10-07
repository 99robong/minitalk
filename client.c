/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:45:01 by junshin           #+#    #+#             */
/*   Updated: 2021/10/07 17:33:10 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void	sigtest(char *str)
{
	int	bit;

	bit = 0;
	while (*str)
	{
		bit = 64;
		while (bit)
		{
			if (bit & *str)
				write(1, "1", 1);
			else
				write(1, "0", 1);
			bit = bit >> 1;
		}
		write(1, "\n", 1);
		str++;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc < 3)
		printf("Usage : ./%s PID \n", argv[0]);
	else
	{
		/*
		if (atoi(argv[2]) == 1)
			kill(atoi(argv[1]), SIGUSR1);
		else if (atoi(argv[2]) == 2)
			kill(atoi(argv[1]), SIGUSR2);
		*/
		sigtest(argv[2]);
	}
}
