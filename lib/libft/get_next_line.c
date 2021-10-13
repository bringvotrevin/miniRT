/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 04:17:08 by yoojlee           #+#    #+#             */
/*   Updated: 2021/05/04 18:57:53 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	static t_backup	*fd_header = NULL;
	t_backup		*node;
	int				flag;

	if (BUFFER_SIZE < 1 || !(node = find_fd(&fd_header, fd)) || line == NULL)
		return (-1);
	while (1)
	{
		flag = read_line(node, line, fd);
		if (flag == -1)
		{
			clear_list(&fd_header);
			return (-1);
		}
		else if (flag == 1)
			break ;
		else if (flag == 0)
		{
			*line = ft_strdup_gnl(node->backup, node->backup_size);
			del_node(&fd_header, fd);
			return (0);
		}
	}
	return (1);
}

t_backup		*find_fd(t_backup **fd_header, int fd)
{
	t_backup	*lst;

	lst = *fd_header;
	while (lst != NULL)
	{
		if (lst->fd == fd)
			break ;
		lst = lst->next;
	}
	if (lst == NULL)
	{
		if (!(lst = (t_backup *)malloc(sizeof(t_backup))))
			return (NULL);
		lst->fd = fd;
		lst->backup = NULL;
		lst->backup_size = 0;
		lst->next = *fd_header;
		*fd_header = lst;
	}
	return (lst);
}

void		del_node(t_backup **fd_header, int fd)
{
	t_backup	*ptr;
	t_backup	*before;

	ptr = *fd_header;
	if (fd == ptr->fd)
	{
		*fd_header = ptr->next;
		free(ptr->backup);
		free(ptr);
		return ;
	}
	before = ptr;
	ptr = ptr->next;
	while (ptr != NULL)
	{
		if (ptr->fd == fd)
		{
			before->next = ptr->next;
			free(ptr->backup);
			free(ptr);
			break ;
		}
		before = ptr;
		ptr = ptr->next;
	}
}

void		clear_list(t_backup **fd_header)
{
	t_backup	*tmp1;
	t_backup	*tmp2;

	tmp1 = *fd_header;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1->backup);
		free(tmp1);
		tmp1 = tmp2;
	}
	*fd_header = NULL;
}
