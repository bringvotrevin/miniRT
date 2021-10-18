/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_parse_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:08:16 by dim               #+#    #+#             */
/*   Updated: 2021/10/18 16:40:39 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_PARSE_UTIL_H
# define DIM_PARSE_UTIL_H
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../util/error.h"
# include "../vector/dim_vector.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "../../header/define.h"
# include "../../header/struct.h"

int			check_input(int	argc, char	**argv);
void		split_vec(t_vec *rgb, char *line);
bool		validate_vec(char *line);
int			validate_float(char *line);
int			count_split_line(char **line);
void		free_split_line(char **split_line);
t_object	*add_object(t_object **head, void *parsed_obj,\
						t_object_toolbox *parsed_toolbox);

#endif