/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:10:50 by junshin           #+#    #+#             */
/*   Updated: 2021/07/31 21:04:00 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

typedef struct s_gnl_list
{
	int					fd;
	char				*string;
	struct s_gnl_list	*prev;
	struct s_gnl_list	*next;
}				t_gnl_list;
char			*ft_strnjoin(char *s1, char *s2, int len2);
char			*ft_splitnewline(char *src, char **dst);

t_gnl_list		*ft_findlst(int fd, t_gnl_list *buf);
t_gnl_list		*ft_lstaddnew(int fd, t_gnl_list *prev);
int				get_next_line(int fd, char **line);
int				isnewline(char *str);
t_gnl_list		*free_lst(t_gnl_list *buf);

#endif
