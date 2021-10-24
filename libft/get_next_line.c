/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junshin <junshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:58:59 by junshin           #+#    #+#             */
/*   Updated: 2021/07/31 21:05:12 by junshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_gnl_list	*fd_list;
	char				read_buff[BUFFER_SIZE + 1];
	int					error;

	if ((fd < 0) || !line || (BUFFER_SIZE <= 0))
		return (-1);
	if (fd_list && fd_list->fd != fd)
		fd_list = ft_findlst(fd, fd_list);
	if (!fd_list)
		fd_list = ft_lstaddnew(fd, fd_list);
	while (!isnewline(fd_list->string))
	{
		error = read(fd, read_buff, BUFFER_SIZE);
		if (error >= 0)
			fd_list->string = ft_strnjoin(fd_list->string, read_buff, error);
		if (error <= 0)
		{
			if (!error)
				*line = ft_strdup(fd_list->string);
			fd_list = free_lst(fd_list);
			return (error);
		}
	}
	*line = ft_splitnewline(fd_list->string, &fd_list->string);
	return (1);
}

int	isnewline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

t_gnl_list	*ft_findlst(int fd, t_gnl_list *buf)
{
	if (buf)
	{
		while (buf->prev)
			buf = buf->prev;
		while (buf->next)
		{
			if (buf->fd == fd)
				return (buf);
			buf = buf->next;
		}
		if (buf->fd == fd)
			return (buf);
	}
	return (ft_lstaddnew(fd, buf));
}

t_gnl_list	*ft_lstaddnew(int fd, t_gnl_list *prev)
{
	t_gnl_list	*new;

	new = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (!new)
		return (0);
	new->fd = fd;
	new->string = ft_strdup("");
	new->next = 0;
	if (prev)
	{
		prev->next = new;
		new->prev = prev;
	}
	else
		new->prev = 0;
	return (new);
}

t_gnl_list	*free_lst(t_gnl_list *buf)
{
	t_gnl_list	*prev;
	t_gnl_list	*next;

	prev = buf->prev;
	next = buf->next;
	if (next)
		next->prev = prev;
	if (prev)
		prev->next = next;
	free(buf->string);
	free(buf);
	if (prev)
		return (prev);
	else if (next)
		return (next);
	else
		return (0);
}
