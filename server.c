/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:35:26 by junshin           #+#    #+#             */
/*   Updated: 2021/10/07 14:01:34 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

int	main(void)
{
	void	usr1(int);
	void	usr2(int);
	int		i;

	signal(SIGUSR1, usr1);
	signal(SIGUSR2, usr2);
	i = 10;
	printf("%ld\n", (long)getpid());
	while (i >= 0)
	{
		printf("%dsed\n", i);
		sleep(1);
		i--;
	}
	return (0);
}

void	usr1(int signum)
{
	printf("USR1\n");
	exit(0);
}

void	usr2(int signum)
{
	printf("USR2\n");
	exit(0);
}
