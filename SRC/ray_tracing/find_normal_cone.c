/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normal_cone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:16:52 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:35:08 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_vector	find_normal_cone(t_object cone, t_vector *point)
{
	t_vector	b;
	t_vector	a;
	t_vector	scaled;
	t_vector	new;
	t_vector	n;

	b = sub_vector(point, &cone.position);
	a = scalar_vector(cos_vector(&b, &cone.direction), &cone.direction);
	n = sub_vector(&a, &b);
	scaled = product_vectors(&b, &n);
	n = product_vectors(&scaled, &b);
	new = normal_vector(n);
	return (new);
}
