/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_light.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:58:59 by dim               #+#    #+#             */
/*   Updated: 2021/08/15 17:46:58 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_LIGHT_H
# define DIM_LIGHT_H
# include "dim_header.h"

typedef struct		s_light
{
	t_vector		origin;
	t_vector		color;
	struct s_light	*next;
}					t_light;

void		light_parsing(t_render *render, char **split_line);
bool		validate_light(double bright, t_vector rgb);
t_light		*save_light(t_vector origin1, double bright, t_vector rgb);

#endif