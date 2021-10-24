/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 03:07:32 by junshin           #+#    #+#             */
/*   Updated: 2021/07/17 22:00:37 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, unsigned int n)
{
	unsigned char	*dp;

	dp = (unsigned char *)dst;
	if (n == 0)
		return ((unsigned char *)0);
	while (n-- > 0)
	{
		if (*(unsigned char *)src == (unsigned char)c)
		{
			*(dp++) = *((unsigned char *)src++);
			return ((unsigned char *)dp);
		}
		*(dp++) = *((unsigned char *)src++);
	}
	return ((unsigned char *)0);
}
