/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 03:48:27 by dim               #+#    #+#             */
/*   Updated: 2021/08/15 17:46:08 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_PARSE_H
# define DIM_PARSE_H
# include "dim_render.h"

typedef struct	s_parser
{
	t_render	*render;
	int			fd;
	char		*line;
	char		**split_line;
}				t_parser;

void		parsing(int argc, char *argv[], t_render *render);
int			check_input(int	argc, char	**argv);
void		find_element(t_parser *parser);
void		split_vec(t_vector *rgb, char *line);
bool		validate_vec(char *line);
int			validate_float(char *line);
int			count_split_line(char **line);
void		free_split_line(char **split_line);

#endif