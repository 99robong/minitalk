/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 22:05:02 by junshin           #+#    #+#             */
/*   Updated: 2021/02/19 23:32:00 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;
	char			*ddest;
	char			*ssrc;

	if (dest == src || n == 0)
		return (dest);
	ddest = (char *)dest;
	ssrc = (char *)src;
	if (ddest > ssrc)
	{
		while (n-- > 0)
			ddest[n] = ssrc[n];
		return (ddest);
	}
	i = 0;
	if (ddest < ssrc)
	{
		while (i < n)
		{
			ddest[i] = ssrc[i];
			i++;
		}
		return (ddest);
	}
	return (0);
}
