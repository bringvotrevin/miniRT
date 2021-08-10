/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 03:48:27 by dim               #+#    #+#             */
/*   Updated: 2021/08/11 02:14:48 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_PARSE_H
# define DIM_PARSE_H
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct  s_world
{
	/* t_objext	*object;
	t_light		*light;
	t_cam		*cam; */
	t_vector	*ambient_light;
}				t_world;

typedef struct	s_control
{
	bool		save;
}				t_control;

typedef struct	s_trace
{
	void		*mlx;
}				t_trace;

typedef struct	s_render
{
	t_world		world;
	t_control	control;
	t_trace		trace;
}				t_render;

typedef struct	s_parser
{
	t_render	*render;
	int			fd;
	char		*line;
	char		**split_line;
}				t_parser;

void	parsing(int argc, char *argv[], t_render *render);
int		check_input(int	argc, char	**argv);
void	find_element(t_parser *parser);
void	amb_light_parsing(t_render *render, char **split_line);
bool	validate_amb_light(double light_ratio, t_vector *rgb);
void	split_vec(t_vector *rgb, char *line);
bool	validate_vec(char *line);
int		validate_float(char *line);
int		count_split_line(char **line);
void	error(char *msg);
void	free_split_line(char **split_line);
t_vector	*save_amb_light(double light_ratio, t_vector *rgb);

#endif