/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:35:11 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:57:56 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

void	find_a_b_c(t_ray *ray, t_object *cylinder, t_val_math *val)
{
	t_vector		delta_p;
	t_vector		tmp;
	t_vector		sub_1;
	t_vector		sub_2;
	double			res;

	delta_p = sub_vector(ray->origin, &cylinder->position);
	res = dot_vector(ray->direction, &cylinder->direction);
	tmp = scalar_vector(res, &cylinder->direction);
	sub_1 = sub_vector(ray->direction, &tmp);
	res = dot_vector(&delta_p, &cylinder->direction);
	tmp = scalar_vector(res, &cylinder->direction);
	sub_2 = sub_vector(&delta_p, &tmp);
	val->a = dot_vector(&sub_1, &sub_1);
	val->b = 2 * dot_vector(&sub_1, &sub_2);
	val->c = dot_vector(&sub_2, &sub_2) - cylinder->size_pow;
}

int		intersect_cylinder(t_ray *ray, t_object object, double *t)
{
	t_val_math	val;
	int			res;

	res = 0;
	find_a_b_c(ray, &object, &val);
	if ((res = discriminant(t, val)) == 0)
		return (0);
	return (res);
}
