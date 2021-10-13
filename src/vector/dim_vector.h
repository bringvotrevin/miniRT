/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_vector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:53:18 by dim               #+#    #+#             */
/*   Updated: 2021/10/13 20:58:17 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

t_vec		create_vec(double x, double y, double z);
t_vec		add_vec(t_vec v1, t_vec v2);
t_vec		minus_vec(t_vec v1, t_vec v2);
t_vec		product_vec(t_vec v, double scalar);
double		dot_vec(t_vec v1, t_vec v2);
t_vec		cross_vec(t_vec v1, t_vec v2);
t_vec		unit_vec(t_vec v);

#endif