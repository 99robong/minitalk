/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 07:28:36 by junshin           #+#    #+#             */
/*   Updated: 2021/02/08 16:24:23 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *dst, int c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		((char *)dst)[i++] = (char)c;
	return (dst);
}
