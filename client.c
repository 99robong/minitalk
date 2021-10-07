/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:45:01 by junshin           #+#    #+#             */
/*   Updated: 2021/10/07 14:02:53 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int	main(int argc, char *argv[])
{
	if (argc < 3)
		printf("Usage : ./%s PID \n", argv[0]);
	else
	{
		if (atoi(argv[2]) == 1)
			kill(atoi(argv[1]), SIGUSR1);
		else if (atoi(argv[2]) == 2)
			kill(atoi(argv[1]), SIGUSR2);
	}
}
