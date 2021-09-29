/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_vector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:53:18 by dim               #+#    #+#             */
/*   Updated: 2021/09/29 17:44:39 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

t_vector		create_vec(double x, double y, double z);
t_vector		add_vec(t_vector v1, t_vector v2);
t_vector		minus_vec(t_vector v1, t_vector v2);
t_vector		product_vec(t_vector v, double scalar);
double			dot_vec(t_vector v1, t_vector v2);
t_vector		cross_vec(t_vector v1, t_vector v2);
t_vector		unit_vec(t_vector v);

#endif