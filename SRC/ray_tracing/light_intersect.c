/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 04:10:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:28:34 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

int		light_intersect(t_rtv1 *rtv1, double *t)
{
	t_val_intersect		val;
	t_val_math			val_t;

	val.i = 0;
	val.num_obj = -1;
	while (val.i < SIZE_OBJ)
	{
		val_t.t1 = 200000.0f;
		val.hit = check_intersect_object(RT, &val_t.t1, val.i, RT->light_ray);
		if (val.hit && val_t.t1 < *t)
			return (0);
		val.i++;
	}
	return (1);
}
