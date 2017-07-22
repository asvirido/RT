/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersect_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:13:50 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:52:10 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_vector	get_intersect_normal(t_rtv1 *rtv1, int num_obj, t_vector *point)
{
	t_vector	normal;

	normal.x = 0;
	normal.y = 0;
	normal.z = 0;
	if (RT_OBJ.id == SPHERE)
		normal = normal_vector(sub_vector(&RT_OBJ.position, point));
	else if (RT_OBJ.id == PLANE)
		set_vector(&normal, &RT_OBJ.direction);
	else if (RT_OBJ.id == DISC)
		set_vector(&normal, &RT_OBJ.direction);
	else if (RT_OBJ.id == CD_DISC)
		set_vector(&normal, &RT_OBJ.direction);
	else if (RT_OBJ.id == CYLINDER)
		normal = find_normal_cylinder(RT_OBJ, point);
	else if (RT_OBJ.id == CONE)
		normal = find_normal_cone(RT_OBJ, point);
	else if (RT_OBJ.id == HALF_SPHERE)
	{
		if (RT_OBJ.light_n == 2)
			set_vector(&normal, &RT_OBJ.direction);
		else
			normal = normal_vector(sub_vector(&RT_OBJ.position, point));
	}
	return (normal);
}
