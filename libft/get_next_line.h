/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:29:19 by yoojlee           #+#    #+#             */
/*   Updated: 2021/07/25 05:09:37 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_backup
{
	int				fd;
	char			*backup;
	int				backup_size;
	char			buffer[BUFFER_SIZE];
	struct s_backup		*next;
}				t_backup;

int				get_next_line(int fd, char **line);
t_backup		*find_fd(t_backup **fd_header, int fd);
int				read_line(t_backup *node, char **line, int fd);
int				malloc_backup(t_backup *node, int read_byte);
int				find_end(t_backup *node, char **line);
int				line_backup_update(t_backup *node, char **line, int i);
char			*ft_strdup_gnl(const char *s, int size);
void			del_node(t_backup **fd_header, int fd);
void			clear_list(t_backup **fd_header);

#endif
