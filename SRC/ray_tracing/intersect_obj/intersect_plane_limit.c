/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane_limit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:58:22 by asvirido          #+#    #+#             */
/*   Updated: 2017/06/09 19:58:23 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

int		intersect_plane_limit(t_ray *ray, t_object plane, double *t)
{
	t_vector	tmp;
	t_val_math	val;

	val.d = dot_vector(&plane.direction, ray->direction);
	if (val.d != 0)
	{
		tmp = sub_vector(&plane.position, ray->origin);
		val.t0 = dot_vector(&tmp, &plane.direction) / val.d;
		if (val.t0 > 0.001f)
		{
			*t = val.t0;
			return (1);
		}
	}
	return (0);
}
