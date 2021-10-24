/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:39:26 by junshin           #+#    #+#             */
/*   Updated: 2021/03/09 14:58:02 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;
	char	*temp;

	i = ft_strlen(src);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	temp = str;
	while (i-- > 0)
		*(str++) = *(src++);
	*str = '\0';
	return (temp);
}
