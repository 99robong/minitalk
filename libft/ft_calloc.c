/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:31:02 by junshin           #+#    #+#             */
/*   Updated: 2021/02/15 10:45:10 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned int nmemb, unsigned int n)
{
	void	*temp;

	temp = malloc(nmemb * n);
	if (!temp)
		return (0);
	ft_bzero(temp, nmemb * n);
	return (temp);
}
