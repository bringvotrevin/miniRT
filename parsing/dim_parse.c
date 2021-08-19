/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 03:44:00 by dim               #+#    #+#             */
/*   Updated: 2021/08/17 03:27:14 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_parse.h"

void	find_element(t_parser *parser)
{
	if (!ft_strcmp(parser->split_line[0], "A"))
		amb_light_parsing(parser->render, parser->split_line);
	else if (!ft_strcmp(parser->split_line[0], "C"))
		cam_parsing(parser->render, parser->split_line);
	else if (!ft_strcmp(parser->split_line[0], "L"))
		light_parsing(parser);
	else if (!ft_strcmp(parser->split_line[0], "sp"))
		sphere_parsing(parser);
	else if (!ft_strcmp(parser->split_line[0], "pl"))
		plane_parsing(parser);
	else if (!ft_strcmp(parser->split_line[0], "cy"))
		cylinder_parsing(parser);
	else
		error("Wrong identifier");
}

int			check_input(int	argc, char	**argv)
{
	int		ext;
	char	*save;
	int 	fd;

	save = "--save";
	if (argc < 2 || argc > 3)
		error("Wrong argument");
	ext = ft_strlen(argv[1]);
	if (ext < 4)
		error("Wrong file");
	if (argv[1][ext - 3] != '.' \
	|| argv[1][ext - 2] != 'r' \
	|| argv[1][ext - 1] != 't')
		error("Wrong file type");
	if (argc == 3)
	{
		if ((ft_strcmp(argv[2], save) != 0))
			error("Wrong argument");
	}
	fd = open(argv[1], O_RDONLY);
	if (fd <= 2)
		error("fd error");
	return (fd);
}

void	parsing(int argc, char *argv[], t_render *render)
{
	t_parser	parser;
	int			gnl;

	parser.render = render;
	parser.line = NULL;
	parser.split_line = NULL;
	parser.fd = check_input(argc, argv);
	while ((gnl = get_next_line(parser.fd, &parser.line)) != -1)
	{
		parser.split_line = ft_chrsplit(parser.line, "\t\n\v\r ");
		if (parser.split_line == NULL)
			error(NULL);
		if (parser.split_line[0] != NULL)
			find_element(&parser);
		if (gnl == 0)
			break ;
		free_split_line(parser.split_line);
		free(parser.line);
		parser.split_line = NULL;
		parser.line = NULL;
	}
	if (gnl == -1)
		error("Read error");
	free_split_line(parser.split_line);
	free(parser.line);
	close(parser.fd);
}

int		main(int argc, char	*argv[])
{
	t_render	render;
	
	parsing(argc, argv, &render);
	return (0);
}