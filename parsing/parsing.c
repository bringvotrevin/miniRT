/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:20:40 by yoojlee           #+#    #+#             */
/*   Updated: 2021/09/16 20:11:36 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "parsing.h"

int		write_content(t_info **info)
{
	t_info	*tmp;
	int		i;

	tmp = *info;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->content[i])
		{
			printf("%s\n", tmp->content[i]);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_add_front(t_info **head, t_info *new)
{
	if (head == NULL || new == NULL)
		return ;
	new->next = *head;
	*head = new;
}

void	ft_add_back(t_info **head, t_info *new)
{
	t_info	*tmp;

	tmp = *head;
	if (head == NULL || new == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int		parsing_front(void)
{
	t_info	*info;
	t_info	*head;
	int		fd;
	char	*line;

	info = NULL;
	head = NULL;
	if ((fd = open("../sphere9.rt", O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
	//	if (info == NULL)
			info = (t_info *)malloc(sizeof(t_info));
		if (info == NULL)
			return (0);
		info->content = NULL;
		info->content = ft_split(line, ' ');
		ft_add_front(&head, info);
//		info->next = head;
//		head = &info;
	//	info = NULL;
		free(line);
	}
	write_content(&head);
	return (1);
}

int		parsing_back(char *file_name)
{
	t_info	*info;
	t_info	*head;
	char	*line;
	int		fd;

	info = NULL;
	head = NULL;
	head = info;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		if (info == NULL)
		{
			info = (t_info *)malloc(sizeof(t_info));
			if (info == NULL)
				return (0);
			info->content = NULL;
			info->next = NULL;
			info->content = ft_split(line, ' ');
			ft_add_back(&head, info);
			free(line);
		}
		info = info->next;

	}
	write_content(&head);
	return (1);
}

int			check_input(int	argc, char	**argv)
{
	int		ext;
	char	*save;
	int 	fd;

	save = "--save";
	if (argc < 2 || argc > 3)
		// return (0); error내용 출력으로 바꿈@
		error("Wrong argument");
	ext = ft_strlen(argv[1]);
	if (ext < 4)
		// return (0); @
		error("Wrong file");
	if (argv[1][ext - 3] != '.' \
	|| argv[1][ext - 2] != 'r' \
	|| argv[1][ext - 1] != 't')
		// return (0); @
		error("Wrong file type");
	if (argc == 3)
	{
		if ((ft_strcmp(argv[2], save) != 0))
			// return (0); @
			error("Wrong argument");
	}
	// fd 추가 @@
	fd = open(argv[2], O_RDONLY);
	if (fd <= 2)
		error(); // error msg ?
	return (fd);
}

/* int		main(int argc, char	*argv[])
{
	if (!(check_input(argc, argv)))
		return (-1);
	parsing_back(argv[1]);
	return (0);
} */
