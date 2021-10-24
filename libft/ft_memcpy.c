/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 02:58:58 by junshin           #+#    #+#             */
/*   Updated: 2021/07/17 21:51:37 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	void	*temp;

	temp = dst;
	if (dst == src)
		return (dst);
	while (n-- > 0)
		*((char *)dst++) = *((char *)src++);
	return (temp);
}
