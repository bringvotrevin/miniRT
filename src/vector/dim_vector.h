/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_vector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:53:18 by dim               #+#    #+#             */
/*   Updated: 2021/10/19 13:13:32 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "../../header/struct.h"
# include <math.h>

t_vec		create_vec(double x, double y, double z);
t_vec		add_vec(t_vec v1, t_vec v2);
t_vec		minus_vec(t_vec v1, t_vec v2);
t_vec		product_vec(t_vec v, double scalar);
t_vec		product_vec2(t_vec v1, t_vec v2);
double		dot_vec(t_vec v1, t_vec v2);
t_vec		cross_vec(t_vec v1, t_vec v2);
t_vec		unit_vec(t_vec v);
t_vec		divide_vec(t_vec v, double scala);
#endif
