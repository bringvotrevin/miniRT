/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 04:45:27 by dim               #+#    #+#             */
/*   Updated: 2021/10/17 04:11:53 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dim_parse_util.h"

bool	validate_sphere(t_vec color)
{
	bool	flag;

	flag = true;
	if (color.x < 0 || color.x > 255
		|| color.y < 0 || color.y > 255
		|| color.z < 0 || color.z > 255)
	 	flag = false;
	return (flag);
}

t_sphere	*save_sphere(t_vec point, double diameter, t_vec color1)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (NULL);
	sphere->center = point;
	sphere->diameter = (diameter / 2);
	sphere->color = color1;
	return (sphere);
}

t_object	*add_object(t_object **head, void *parsed_obj,\
						t_object_toolbox *parsed_toolbox)
{
	t_object	*new_object;

	new_object = (t_object *)malloc(sizeof(t_object));
	if (new_object == NULL || parsed_obj == NULL)
		return (NULL);
	new_object->object = parsed_obj;
	new_object->toolbox = parsed_toolbox;
	new_object->next = *head;
	*head = new_object;
	return (new_object);
}

void		sphere_parsing(t_render *render, char **split_line)
{
	t_vec	point;
	double		diameter;
	t_vec	color;
	
	printf("here\n");
	if (count_split_line(split_line) != 4)
		error("Information count error on Sphere");
	if (!validate_vec(split_line[1])
		|| !validate_float(split_line[2])
		|| !validate_vec(split_line[3]))
		error("Information error on Sphere");
	printf("split_line1:%s\n", split_line[1]);
	split_vec(&point, split_line[1]);
	diameter = ft_atof(split_line[2]);
	split_vec(&color, split_line[3]);
	if (!validate_sphere(color))
		error("Information range error on Sphere");
	if (add_object(&render->world.object,\
				save_sphere(point, diameter, color),\
				&render->world.sphere_toolbox) == NULL)
		error("Parsing Sphere error");
}

