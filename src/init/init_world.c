/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:19:59 by dim               #+#    #+#             */
/*   Updated: 2021/10/16 15:17:29 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  팡팡코드

#include "../../header/minirt.h"

void	init_world(t_world *world)
{
	world->object = NULL;
	world->light = NULL;
	world->cam = NULL;
	world->ambient_light = NULL;
//	init_plane_toolbox(&world->plane_toolbox);
//	init_sphere_toolbox(&world->sphere_toolbox);
//	init_cylinder_toolbox(&world->cylinder_toolbox);
}

/* void					init_plane_toolbox(t_object_toolbox *box)
{
	box->hit = hit_plane;
	box->clear = clear_plane;
}

void					init_sphere_toolbox(t_object_toolbox *box)
{
	box->move = move_sphere;
	box->rotate = rotate_sphere;
	box->stretch = stretch_sphere;
	box->hit = hit_sphere;
	box->clear = clear_sphere;
	box->refresh = refresh_sphere;
	box->stretch_mode = 0;
}

void					init_cylinder_toolbox(t_object_toolbox *box)
{
	box->move = move_cylinder;
	box->rotate = rotate_cylinder;
	box->stretch = stretch_cylinder;
	box->hit = hit_cylinder;
	box->clear = clear_cylinder;
	box->refresh = refresh_cylinder;
	box->stretch_mode = 0;
}
 */