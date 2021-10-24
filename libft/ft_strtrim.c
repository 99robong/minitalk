/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:19:02 by junshin           #+#    #+#             */
/*   Updated: 2021/07/17 22:16:49 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	n;
	char			*temp;

	if (!(s1 && set))
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (!*s1)
		return (ft_strdup(""));
	n = ft_strlen(s1);
	while (*(s1 + n - 1) && ft_strchr(set, *(s1 + n - 1)))
		n--;
	temp = (char *)malloc(sizeof(char) * (n + 1));
	if (!temp)
		return (0);
	ft_memcpy(temp, s1, n + 1);
	temp[n] = '\0';
	return (temp);
}
