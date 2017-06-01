/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_disc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 05:01:40 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/26 05:01:42 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

int		intersect_disc(t_ray *ray, t_disk *disk, double *t)
{
	t_vector	tmp;
	t_val_math	val;
	t_vector	p;

	val.d = dot_vector(disk->normal, ray->direction);
	if (val.d != 0)
	{
		tmp = sub_vector(disk->position, ray->origin);
		val.t0 = dot_vector(&tmp, disk->normal) / val.d;
		if (val.t0 > 0.001)
		{
		   tmp = scalar_vector(val.t0, ray->direction);
		   p = add_vector(ray->origin, &tmp);
		   tmp = sub_vector(&p, disk->position);
		   val.d = dot_vector(&tmp, &tmp);
		   if (sqrtf(val.d) <= disk->radius)
		   {
			   *t = val.t0;
			   return (1);
		   }
		}
	}
	return (0);
}
