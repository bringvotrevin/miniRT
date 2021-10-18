/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 04:44:23 by dim               #+#    #+#             */
/*   Updated: 2021/10/18 16:37:18 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_parse_util.h"

void		free_split_line(char **split_line)
{
	char	**ptr;

	ptr = split_line;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(split_line);
}

/* void		error(char *msg)
{
	printf("%s\n", msg);
	exit(0);
} */

void	split_vec(t_vec *rgb, char *line)
{
	char		**split_line;

	split_line = ft_split(line, ',');
	if (!split_line)
		error(NULL);
	rgb->x = ft_atof(split_line[0]);
	rgb->y = ft_atof(split_line[1]);
	rgb->z = ft_atof(split_line[2]);
	free_split_line(split_line);
}

bool		validate_vec(char *line)
{
	char	**split_line;
	char	**ptr;
	bool	flag;

	flag = true;
	split_line = ft_split(line, ',');
	if (split_line == NULL)
		flag = false;
	ptr = split_line;
	while (*ptr)
	{
		if (!validate_float(*ptr))
			flag = false;
		ptr++;
	}
	free_split_line(split_line);
	return (flag);
}

int		validate_float(char *line)
{
	if (*line == '-' || *line == '+')
		line++;
	while (ft_isdigit(*line))
		line++;
	if (*line == '.')
		line++;
	while (ft_isdigit(*line))
		line++;
	if (*line != 0)
		return (0);
	return (1);
}

int		count_split_line(char **line)
{
	int		count;

	count = 0;
	while (*line++)
		count++;
	return (count);
}