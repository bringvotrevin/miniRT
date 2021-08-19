/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_amb_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:58:13 by dim               #+#    #+#             */
/*   Updated: 2021/08/15 17:49:53 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_AMB_LIGHT_H
# define DIM_AMB_LIGHT_H
# include "dim_render.h"

void		amb_light_parsing(t_render *render, char **split_line);
bool		validate_amb_light(double light_ratio, t_vector *rgb);
t_vector	*save_amb_light(double light_ratio, t_vector *rgb);

#endif