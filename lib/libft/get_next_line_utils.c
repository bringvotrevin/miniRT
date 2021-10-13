/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:24:14 by yoojlee           #+#    #+#             */
/*   Updated: 2021/05/04 18:38:57 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_line(t_backup *node, char **line, int fd)
{
	int		read_byte;

	if (node->backup_size != 0 && find_end(node, line) == 1)
		return (1);
	if ((read_byte = read(fd, node->buffer, BUFFER_SIZE)) < 0)
		return (-1);
	if ((read_byte > 0) && malloc_backup(node, read_byte))
		return (-1);
	else if (read_byte == 0)
		return (0);
	return (find_end(node, line));
}

int		malloc_backup(t_backup *node, int read_byte)
{
	char	*buf;
	int		i;
	int		j;

	if (!(buf = (char *)malloc(sizeof(char) * (node->backup_size + read_byte))))
		return (1);
	i = 0;
	while (i < node->backup_size)
	{
		buf[i] = node->backup[i];
		i++;
	}
	j = 0;
	while (j < read_byte)
	{
		buf[i] = node->buffer[j];
		i++;
		j++;
	}
	free(node->backup);
	node->backup = buf;
	node->backup_size += read_byte;
	return (0);
}

int		find_end(t_backup *node, char **line)
{
	int	i;

	i = 0;
	while (i < node->backup_size)
	{
		if (node->backup[i] == '\n')
			break ;
		i++;
	}
	if (i < node->backup_size)
	{
		if (line_backup_update(node, line, i))
			return (-1);
		return (1);
	}
	return (2);
}

int		line_backup_update(t_backup *node, char **line, int i)
{
	int		j;
	char	*buf;
	int		new_size;

	if (!(*line = ft_strdup_gnl(node->backup, i)))
		return (1);
	j = 0;
	new_size = node->backup_size - i - 1;
	if (!(buf = (char *)malloc(sizeof(char) * (new_size))))
		return (1);
	while (++i < node->backup_size)
	{
		buf[j] = node->backup[i];
		j++;
	}
	free(node->backup);
	node->backup = buf;
	node->backup_size = new_size;
	return (0);
}

char	*ft_strdup_gnl(const char *s, int size)
{
	int		i;
	char	*cpy;

	if (!(cpy = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
