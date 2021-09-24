/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_sphere_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 04:45:27 by dim               #+#    #+#             */
/*   Updated: 2021/09/24 04:28:22 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_parse.h"
#include "dim_sphere.h"

bool	validate_sphere(t_vector rgb)
{
	bool	flag;

	flag = true;
	if (rgb.x < 0 || rgb.x > 255 || \
	rgb.y < 0 || rgb.y > 255 || \
	rgb.z < 0 || rgb.z > 255)
	 	flag = false;
	return (flag);
}

t_sphere	*save_sphere(t_vector origin, double diameter, t_vector rgb1)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (NULL);
	sphere->center = origin;
	sphere->radius = (diameter / 2);
	sphere->rgb = rgb1;
	return (sphere);
}

void		sphere_parsing(t_render *render, char **split_line)
{
	t_vector	origin;
	double		diameter;
	t_vector	rgb;

	if (count_split_line(split_line) != 4)
		error("Information count error on Sphere");
	if (!validate_vec(split_line[1]) ||\
	 !validate_float(split_line[2]) ||\
	 !validate_vec(split_line[3]))
		error("Information error on Sphere");
	split_vec(&origin, split_line[1]);
	diameter = ft_atof(split_line[3]);
	split_vec(&rgb, split_line[2]);
	if (!validate_sphere(rgb))
		error("Information range error on Sphere");
	render->world.object->object = save_sphere(origin, diameter, rgb);
	if (render->world.object->object == NULL)
		error(NULL);
}

