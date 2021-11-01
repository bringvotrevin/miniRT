/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:08:16 by dim               #+#    #+#             */
/*   Updated: 2021/11/01 20:23:10 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../vector/vector.h"
# include "../../lib/libft/libft.h"
# include "../../lib/libft/get_next_line.h"
# include "../../header/minirt.h"

typedef struct s_parser
{
	t_render	*render;
	int			fd;
	char		*line;
	char		**split_line;
}				t_parser;

int			check_input(int	argc, char	**argv);
void		split_vec(t_vec *xyz, char *line);
bool		validate_vec(char *line);
int			validate_float(char *line);
int			count_split_line(char **line);
void		free_split_line(char **split_line);
void		parsing(int argc, char *argv[], t_render *render);
void		find_element(t_parser *parser);
void		amb_light_parsing(t_render *render, char **split_line);
void		light_parsing(t_render *render, char **split_line);
void		cam_parsing(t_render *render, char **split_line);
void		cylinder_parsing(t_render *render, char **split_line);
void		plane_parsing(t_render *render, char **split_line);
void		sphere_parsing(t_render *render, char **split_line);
t_object	*add_object(t_object **head, void *parsed_obj, \
						int (*hit)(void *, t_ray *, t_hit *));

#endif