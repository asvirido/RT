/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cd_disc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 18:17:38 by asvirido          #+#    #+#             */
/*   Updated: 2017/07/19 18:17:39 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

t_vector		g_tmp;
t_val_math		g_val;
t_vector		g_p;

int		intersect_cd_disc(t_ray *ray, t_object object, double *t)
{
	g_val.d = dot_vector(&object.direction, ray->direction);
	if (g_val.d != 0)
	{
		g_tmp = sub_vector(&object.position, ray->origin);
		g_val.t0 = dot_vector(&g_tmp, &object.direction) / g_val.d;
		if (g_val.t0 > 0.001)
		{
			g_tmp = scalar_vector(g_val.t0, ray->direction);
			g_p = add_vector(ray->origin, &g_tmp);
			g_tmp = sub_vector(&g_p, &object.position);
			g_val.d = dot_vector(&g_tmp, &g_tmp);
			if (sqrtf(g_val.d) <= object.size)
			{
				if (sqrtf(g_val.d) <= object.size / 3)
					return (0);
				else
				{
					*t = g_val.t0;
					return (1);
				}
			}
		}
	}
	return (0);
}
