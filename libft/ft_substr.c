/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:32:48 by junshin           #+#    #+#             */
/*   Updated: 2021/02/09 10:12:30 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int n)
{
	char	*temp;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	temp = malloc(sizeof(char) * n + 1);
	if (!temp)
		return (0);
	temp = ft_memcpy(temp, s + start, n);
	temp[n] = '\0';
	return (temp);
}
