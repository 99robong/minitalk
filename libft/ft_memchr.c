/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 22:43:55 by junshin           #+#    #+#             */
/*   Updated: 2021/02/15 10:06:17 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char	*ss;

	ss = (unsigned char *)s;
	while (n--)
	{
		if (*ss == (unsigned char)c)
			return (ss);
		ss++;
	}
	return (0);
}
