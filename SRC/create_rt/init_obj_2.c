/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkachyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:22:09 by otkachyk          #+#    #+#             */
/*   Updated: 2017/07/21 16:22:10 by otkachyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	parcing_shines(t_rtv1 *rtv1)
{
	int		num_obj;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
	{
		if (RT_OBJ.shines <= 0)
			error_exit("Bad shines: too small shines [1-600]");
		if (RT_OBJ.shines > 600)
			error_exit("Bad shines: too big shines [1-600]");
	}
}

void	parcing_reftact(t_rtv1 *rtv1)
{
	int		num_obj;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
	{
		if (RT_OBJ.refraction == 1 && RT_OBJ.reflection == 1)
			RT_OBJ.reflection = 0;
	}
}

void	parcing_half_sphere(t_rtv1 *rtv1)
{
	int			num_obj;
	t_vector	tmp;
	double		len;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
	{
		if (RT_OBJ.id == HALF_SPHERE)
		{
			tmp = sub_vector(&RT_OBJ.position, &RT_OBJ.position);
			len = module_vector(&tmp) * module_vector(&tmp);
			RT_OBJ.radius_disc = sqrt(RT_OBJ.size_pow - len);
		}
	}
}

void	parcing_cone(t_rtv1 *rtv1)
{
	int		num_obj;
	double	angle;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
	{
		if (RT_OBJ.id == CONE)
		{
			if (RT_OBJ.size >= 360 || RT_OBJ.size <= 0)
				error_exit("ERROR angle cone size");
			angle = RT_OBJ.size * RAD;
			RT_OBJ.cone_cos_two = cos(angle) * cos(angle);
			RT_OBJ.cone_sin_two = sin(angle) * sin(angle);
			RT_OBJ.two_cone_cos_two = 2 * (cos(angle) * cos(angle));
			RT_OBJ.two_cone_sin_two = 2 * (sin(angle) * sin(angle));
		}
	}
}
