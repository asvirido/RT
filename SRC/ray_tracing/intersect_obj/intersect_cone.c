/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:34:56 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 04:03:59 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

static void		find_a_b_c(t_ray *ray, t_object cone, t_val_math *val)
{
	t_vector		mult;
	t_vector		sub_1;
	t_vector		sub_2;
	double			r1;
	double			r2;

	val->dist = sub_vector(ray->origin, &cone.position);
	r1 = dot_vector(ray->direction, &cone.direction);
	mult = scalar_vector(r1, &cone.direction);
	sub_1 = sub_vector(ray->direction, &mult);
	r2 = dot_vector(&val->dist, &cone.direction);
	mult = scalar_vector(r2, &cone.direction);
	sub_2 = sub_vector(&val->dist, &mult);
	val->a = CONE_COS_2 * dot_vector(&sub_1, &sub_1) - CONE_SIN_2 * (r1 * r1);
	val->b = CONE_COS_22 * dot_vector(&sub_1, &sub_2) - CONE_SIN_22 * (r1 * r2);
	val->c = CONE_COS_2 * dot_vector(&sub_2, &sub_2) - CONE_SIN_2 * (r2 * r2);
}

int				intersect_cone(t_ray *ray, t_object cone, double *t)
{
	t_val_math		val;
	int				res;

	res = 0;
	find_a_b_c(ray, cone, &val);
	res = discriminant(t, val);
	return (res);
}
