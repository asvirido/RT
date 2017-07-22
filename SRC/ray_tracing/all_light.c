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

t_vector	g_eye_dir;

static inline void	color_multi(t_color *color, double a)
{
	color->red *= a;
	color->blue *= a;
	color->green *= a;
}

void				lambert_light(t_rtv1 *rtv1, t_val_vector *val,
	int *hit, int id)
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
		if ((id == PLANE || id == DISC || id == CD_DISC) && dot <= 0)
		{
			anti_vector(&val->n_point);
			dot = cos_vector(&val->n_point, &l_dir);
		}
		lambert_component = MAX(dot, 0.0);
		color_multi(&val->rgb[i], lambert_component + L.ambient);
	}
}

void				cel_shaded(t_rtv1 *rtv1, t_val_vector *val,
	int *hit, int id)
{
	int			i;
	double		dot;

	i = -1;
	while (++i < SIZE_LIGHT)
	{
		if (hit[i] == 0)
			continue ;
		val->tmp = normal_vector(sub_vector(&val->point, &L.position));
		dot = cos_vector(&val->n_point, &val->tmp);
		if ((id == PLANE || id == DISC || id == CD_DISC) && dot <= 0)
		{
			anti_vector(&val->n_point);
			dot = cos_vector(&val->n_point, &val->tmp);
		}
		dot = MAX(dot, 0.0);
		if (dot > 0.95)
			continue ;
		else if (dot > 0.5)
			color_multi(&val->rgb[i], 0.7);
		else if (dot > 0.2)
			color_multi(&val->rgb[i], 0.2);
		else
			color_multi(&val->rgb[i], 0.05);
	}
}

void				blinn_fong_light(t_rtv1 *rtv1, t_val_vector *val,
	int *hit, t_object obj)
{
	t_vector	l_dir;
	double		dot;
	double		beta;
	int			i;

	i = -1;
	while (++i < SIZE_LIGHT)
	{
		if (hit[i] == 0)
			continue ;
		l_dir = normal_vector(sub_vector(&val->point, &L.position));
		dot = cos_vector(&val->n_point, &l_dir);
		if ((obj.id == PLANE || obj.id == DISC || obj.id == CD_DISC)
			&& dot <= 0)
		{
			anti_vector(&val->n_point);
			dot = cos_vector(&val->n_point, &l_dir);
		}
		beta = MAX(dot, 0.0);
		set_vector(&g_eye_dir, RAY_DIRECTION);
		anti_vector(&g_eye_dir);
		l_dir = normal_vector(sub_vector(&l_dir, &g_eye_dir));
		beta += pow(MAX(dot_vector(&val->n_point, &l_dir), 0), obj.shines);
		color_multi(&val->rgb[i], L.ambient + beta);
	}
}

void				all_light(t_rtv1 *rtv1, t_val_vector *val,
	int *hit, int num_obj)
{
	if (OPTION->lambert_light == TRUE)
		lambert_light(RT, val, hit, RT_OBJ.id);
	else if (OPTION->cel_shaded == TRUE)
		cel_shaded(RT, val, hit, RT_OBJ.id);
	else if (OPTION->blinn_fong == TRUE)
		blinn_fong_light(RT, val, hit, RT_OBJ);
	else if (OPTION->view_normal || OPTION->view_point)
		view_point_or_normal(RT, val);
}
