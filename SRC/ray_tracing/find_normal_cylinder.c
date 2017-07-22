/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normal_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:16:58 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:34:52 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_vector	find_normal_cylinder(t_object cylinder, t_vector *point)
{
	t_vector	a;
	t_vector	c;
	t_vector	tmp1;
	t_vector	new;
	double		b;

	a = sub_vector(point, &cylinder.position);
	b = dot_vector(&a, &cylinder.direction);
	c = scalar_vector(b, &cylinder.direction);
	tmp1 = sub_vector(&c, &a);
	new = division_vector(&tmp1, cylinder.size);
	return (new);
}
