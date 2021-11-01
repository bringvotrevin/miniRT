/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 03:44:00 by dim               #+#    #+#             */
/*   Updated: 2021/11/01 17:28:45 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	find_element(t_parser *parser)
{
	if (!ft_strcmp(parser->split_line[0], "A"))
		amb_light_parsing(parser->render, parser->split_line);
	else if (!ft_strcmp(parser->split_line[0], "C"))
		cam_parsing(parser->render, parser->split_line);
	else if (!ft_strcmp(parser->split_line[0], "L"))
		light_parsing(parser->render, parser->split_line);
	else if (!ft_strcmp(parser->split_line[0], "sp"))
		sphere_parsing(parser->render, parser->split_line);
	else if (!ft_strcmp(parser->split_line[0], "pl"))
		plane_parsing(parser->render, parser->split_line);
	else if (!ft_strcmp(parser->split_line[0], "cy"))
		cylinder_parsing(parser->render, parser->split_line);
	else
		error("Wrong identifier");
}

int	check_input(int	argc, char	**argv)
{
	int		ext;
	int		fd;

	if (argc != 2)
		error("Wrong argument");
	ext = ft_strlen(argv[1]);
	if (ext < 4)
		error("Wrong file");
	if (argv[1][ext - 3] != '.'
		|| argv[1][ext - 2] != 'r'
		|| argv[1][ext - 1] != 't')
		error("Wrong file type");
	fd = open(argv[1], O_RDONLY);
	if (fd <= 2)
		error("fd error");
	return (fd);
}

void	check_essential_element(t_render *render)
{
	if (render->world.ambient_light == NULL
		|| render->world.cam == NULL
		|| render->world.light == NULL)
		error("Missing essential element in file");
}

void	parsing(int argc, char *argv[], t_render *render)
{
	t_parser	parser;
	int			res;

	parser.render = render;
	parser.line = NULL;
	parser.fd = check_input(argc, argv);
	while (1)
	{
		res = get_next_line(parser.fd, &parser.line);
		if (res < 0)
			error("Read error");
		parser.split_line = ft_chrsplit(parser.line, "\t\n\v\r ");
		if (parser.split_line == NULL)
			error(NULL);
		if (parser.split_line[0] != NULL)
			find_element(&parser);
		free_split_line(parser.split_line);
		free(parser.line);
		parser.line = NULL;
		if (res == 0)
			break ;
	}
	check_essential_element(render);
	close(parser.fd);
}
