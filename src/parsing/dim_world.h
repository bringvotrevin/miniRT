/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_world.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 04:16:30 by dim               #+#    #+#             */
/*   Updated: 2021/10/14 15:59:16 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIM_WORLD_H
# define DIM_WORLD_H
# include "dim_cam.h"
# include "dim_light.h"
# include "dim_object.h"

typedef struct  s_world
{
	t_object			*object;
	t_light				*light;
	t_cam				*cam;
	t_vec				*ambient_light;
	t_object_toolbox    plane_toolbox;
	t_object_toolbox    sphere_toolbox;
	t_object_toolbox    cylinder_toolbox;
}				t_world;

#endif