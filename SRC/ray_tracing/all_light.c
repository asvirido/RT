/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:23:14 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:21:20 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void 	anti_vector(t_vector *v)
{
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
}

static inline void 	color_multi(t_color *color, double a)
{
	color->red *= a;
	color->blue *= a;
	color->green *= a;
}

void 	lambert_light(t_rtv1 *rtv1, t_val_vector *val, int *hit)
{
	int			i;
	double		dot;
	double		lambert_component;
	t_vector	l_dir;

	i = -1;
	while (++i < SIZE_LIGHT)
	{
		if (hit[i] == 0)
			continue ;
		l_dir = normal_vector(sub_vector(&val->point, &L.position));
		dot = cos_vector(&val->n_point, &l_dir);
		// if (dot <= 0)
		// {
		// 	anti_vector(&val->n_point);
		// 	dot = cos_vector(&val->n_point, &l_dir);
		// }
		lambert_component = MAX(dot, 0.0);
		color_multi(&val->rgb[i], lambert_component);
	}
}

void 	cel_shaded(t_rtv1 *rtv1, t_val_vector *val, int *hit)
{
	int			i;
	double		dot;
	double		lambert_component;
	t_vector	l_dir;

	i = -1;
	while (++i < SIZE_LIGHT)
	{
		if (hit[i] == 0)
			continue ;
		l_dir = normal_vector(sub_vector(&val->point, &L.position));
		dot = cos_vector(&val->n_point, &l_dir);
		lambert_component = MAX(dot, 0.0);
		if (lambert_component > 0.95)
			continue ;
		else if (lambert_component > 0.5)
			color_multi(&val->rgb[i], 0.7);
		else if (lambert_component > 0.2)
			color_multi(&val->rgb[i], 0.2);
		else
			color_multi(&val->rgb[i], 0.05);
	}
}


void	view_point_or_normal(t_rtv1 *rtv1, t_val_vector *val)
{
	t_color		color;
	t_vector		n_point;
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

void 	blinn_fong_light(t_rtv1 *rtv1, t_val_vector *val, int *hit)
{
	t_vector		l_dir;
	t_vector 		eye_vec;
	t_vector 		halfwayVector;
	t_vector 		r;
	t_vector		tmp;

	double 	shiness = 2;
	double 	dot;
	double	lambert_component;
	double	specular;
	int		i;

	i = -1;
	while (++i < SIZE_LIGHT)
	{
		if (hit[i] == 0)
			continue ;
		l_dir = normal_vector(sub_vector(&val->point, &L.position));
		dot = cos_vector(&val->n_point, &l_dir);
		lambert_component = MAX(dot, 0.0);
		t_vector eye_dir;
		set_vector(&eye_dir, RAY_DIRECTION);
		anti_vector(&eye_dir);
		t_vector add = normal_vector(sub_vector(&l_dir, &eye_dir));
		specular = pow(MAX(dot_vector(&val->n_point, &add), 0), shiness);
		val->rgb[i].red = val->rgb[i].red * (0.1 + lambert_component + specular);
		val->rgb[i].green = val->rgb[i].green * (0.1 + lambert_component + specular);
		val->rgb[i].blue = val->rgb[i].blue * (0.1 + lambert_component + specular);
	}
}

void	all_light(t_rtv1 *rtv1, t_val_vector *val, int *hit, int num_obj)
{
	if (OPTION->lambert_light == TRUE)
		lambert_light(RT, val, hit);
	else if (OPTION->cel_shaded == TRUE)
		cel_shaded(RT, val, hit);
	else if (OPTION->blinn_fong == TRUE)
		blinn_fong_light(RT, val, hit);
	else if (OPTION->view_normal || OPTION->view_point)
		view_point_or_normal(RT, val);
}
