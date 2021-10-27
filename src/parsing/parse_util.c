/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 04:44:23 by dim               #+#    #+#             */
/*   Updated: 2021/10/28 02:27:53 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

void	split_vec(t_vec *xyz, char *line)
{
	char		**split_line;

	split_line = ft_split(line, ',');
	if (!split_line)
		error(NULL);
	if (count_split_line(split_line) != 3)
		error("Check Information : [x,y,z]");
	xyz->x = ft_atof(split_line[0]);
	xyz->y = ft_atof(split_line[1]);
	xyz->z = ft_atof(split_line[2]);
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