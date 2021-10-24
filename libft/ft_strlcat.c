/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 07:56:29 by junshin           #+#    #+#             */
/*   Updated: 2021/02/08 16:27:26 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	num;
	unsigned int	num2;

	num = 0;
	num2 = 0;
	while (src[num])
		num++;
	if (size == 0)
		return (num);
	while (dest[num2])
		num2++;
	if (size < num2)
		return (num + size);
	i = 0;
	while (i + num2 + 1 < size && src[i])
	{
		dest[num2 + i] = src[i];
		i++;
	}
	dest[num2 + i] = '\0';
	return (num + num2);
}
