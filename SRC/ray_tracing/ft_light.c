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

t_color		ft_light(t_rtv1 *rtv1, double *t_min, int num_obj)
{
	t_color			color;

	RT->val->point = find_point_intersect(RT, t_min);
	RT->val->n_point = get_intersect_normal(RT, num_obj, &RT->val->point);
	set_vector(L_RAY_ORIGIN, &RT->val->point);
	all_shadow(RT, num_obj, RT->val, RT->hit);
	all_light(RT, RT->val, RT->hit);
	midle_color(RT->val->rgb, SIZE_LIGHT, &color);
	protected_color(&color);
	return (color);
}
