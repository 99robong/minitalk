/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:41:02 by junshin           #+#    #+#             */
/*   Updated: 2021/07/17 22:14:57 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup_char(const char *src, char c, char **result,
unsigned int i)
{
	int		n;
	char	*str;
	char	*temp;

	n = 0;
	while (src[n] != c && src[n] != '\0')
		n++;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
	{
		while (i--)
			free(result[i]);
		free(result);
	}
	if (!str)
		return (0);
	temp = str;
	while (n-- > 0)
		*(str++) = *(src++);
	*str = '\0';
	return (temp);
}

static unsigned int	ft_splitcount(char const *s, char c)
{
	unsigned int	n;

	n = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			while (*s != c && *s)
				s++;
			n++;
		}
		while (*s == c && *s)
			s++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	char			*temp;
	unsigned int	n;
	unsigned int	i;

	if (!s)
		return (0);
	n = ft_splitcount(s, c);
	temp = (char *)s;
	result = (char **)malloc(sizeof(char *) * (n + 1));
	if (!result)
		return (0);
	i = -1;
	while (++i < n)
	{
		while (*temp == c && *temp)
			temp++;
		result[i] = ft_strdup_char(temp, c, result, i);
		while (*temp != c && *temp)
			temp++;
		while (*temp == c && *temp)
			temp++;
	}
	result[i] = 0;
	return (result);
}
