/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 03:48:27 by dim               #+#    #+#             */
/*   Updated: 2021/09/17 18:24:44 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_PARSE_H
# define DIM_PARSE_H
# include "dim_render.h"
# include "dim_parse_util.h"

typedef struct	s_parser
{
	t_render	*render;
	int			fd;
	char		*line;
	char		**split_line;
}				t_parser;

void	parsing(int argc, char *argv[], t_render *render);
void	find_element(t_parser *parser);

void	amb_light_parsing(t_render *render, char **split_line);
void	light_parsing(t_render *render, char **split_line);
void	cam_parsing(t_render *render, char **split_line);
void	cylinder_parsing(t_render *render, char **split_line);
void	plane_parsing(t_render *render, char **split_line);
void	sphere_parsing(t_render *render, char **split_line);

#endif