/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:04:30 by junshin           #+#    #+#             */
/*   Updated: 2021/02/09 01:26:12 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, unsigned int n)
{
	unsigned int	i;

	i = ft_strlen(little);
	if (!i)
		return ((char *)big);
	while (*big && n >= i)
	{
		if (*big == *little)
		{
			if (!ft_strncmp(big, little, i))
				return ((char *)big);
		}
		big++;
		n--;
	}
	return (0);
}
