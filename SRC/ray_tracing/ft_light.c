/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:29:51 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:26:03 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

static void	init_rgb_all_light(t_rtv1 *rtv1, int num_obj, t_val_vector *val)
{
	int		i;

	i = -1;
	while (++i < SIZE_LIGHT)
	{
		RT->hit[i] = 1;
		val->rgb[i] = get_color(RT, num_obj);
	}
}

t_color		ft_light(t_rtv1 *rtv1, double *t_min, int num_obj)
{
	t_color			color;

	RT->val->point = point_intersect(RT->ray, t_min);
	RT->val->n_point = get_intersect_normal(RT, num_obj, &RT->val->point);
	init_rgb_all_light(RT, num_obj, RT->val);
	set_vector(L_RAY_ORIGIN, &RT->val->point);
	if (OPTION->shadow == TRUE)
		all_shadow(RT, num_obj, RT->val, RT->hit);
	all_light(RT, RT->val, RT->hit, num_obj);
	midle_color(RT->val->rgb, SIZE_LIGHT, &color);
	protected_color(&color);
	return (color);
}
