/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkachyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:01:26 by otkachyk          #+#    #+#             */
/*   Updated: 2017/07/21 18:01:26 by otkachyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_color				fast_intersect(t_rtv1 *rtv1, int i)
{
	t_val_intersect		val;
	t_val_math			val_t;
	t_color				color;

	val.i = -1;
	val.num_obj = -1;
	val_t.t0 = 2000000.0f;
	while (++val.i < SIZE_OBJ)
	{
		val_t.t1 = 2000000.0f;
		val.hit = check_intersect_object(RT, &val_t.t1, val.i, RT->ray);
		if (val.hit != 0 && val_t.t1 < val_t.t0)
		{
			val_t.t0 = val_t.t1 - 1;
			val.num_obj = val.i;
		}
	}
	if (val.num_obj != -1 && OPTION->light_off_on == 1)
		color = ft_light(rtv1, &val_t.t0, val.num_obj);
	else if (val.num_obj != -1 && OPTION->light_off_on == 0)
		color = get_color(rtv1, val.num_obj);
	else
		set_color(&color, BACKGROUND.red, BACKGROUND.blue, BACKGROUND.green);
	(val.num_obj != -1) ? (RT->screen[i].id = val.num_obj) : 0;
	return (color);
}

void				anti_vector(t_vector *v)
{
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
}

void				view_point_or_normal(t_rtv1 *rtv1, t_val_vector *val)
{
	t_color		color;
	t_vector	n_point;
	int			i;

	i = -1;
	if (OPTION->view_point == TRUE)
		n_point = normal_vector(val->point);
	else
		set_vector(&n_point, &val->n_point);
	while (++i < SIZE_LIGHT)
	{
		val->rgb[i].red = fabs(n_point.x);
		val->rgb[i].green = fabs(n_point.y);
		val->rgb[i].blue = fabs(n_point.z);
	}
}
