/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:02:20 by junshin           #+#    #+#             */
/*   Updated: 2021/07/31 21:05:28 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin(char *s1, char *s2, int len2)
{
	int		len1;
	int		i;
	char	*join;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	join = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join)
		return (0);
	i = 0;
	while (i < len1)
	{
		join[i] = s1[i];
		i++;
	}
	free(s1);
	while (i < len1 + len2)
		join[i++] = *((char *)s2++);
	join[len1 + len2] = '\0';
	return (join);
}

char	*ft_splitnewline(char *src, char **dst)
{
	int		size;
	char	*result;

	size = 0;
	while (src[size] != '\n')
	{
		if (src[size] == '\0')
		{
			if (!size)
			{
				*dst = ft_strdup("\0");
				return (ft_strdup("\0"));
			}
			else
				break ;
		}
		size++;
	}
	src[size] = '\0';
	result = ft_strdup(src);
	*dst = ft_strdup(src + size + 1);
	free(src);
	return (result);
}
