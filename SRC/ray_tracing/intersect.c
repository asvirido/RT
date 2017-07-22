/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:57:54 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:37:39 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

t_vector		g_normal;
t_vector		g_point;
t_vector		g_dir_point;
double			g_n1;
double			g_n2;
double			g_n;
double			g_c1;
double			g_c2;
t_vector		g_tmp;
double			g_tmp2;
t_vector		g_rr;
t_vector		g_temp;
int				g_num_obj;
int				g_hit;
double			g_t0;
double			g_t1;
int				g_i;
int				g_depth;

static inline void	refraction(t_rtv1 *rtv1)
{
	t_vector	r1;

	g_point = point_intersect(RT->ray, &g_t0);
	g_normal = get_intersect_normal(RT, g_num_obj, &g_point);
	g_c1 = -1 * dot_vector(&g_normal, RAY_DIRECTION);
	g_normal = scalar_vector(g_c1, &g_normal);
	g_normal = scalar_vector(2, &g_normal);
	r1 = add_vector(RAY_DIRECTION, &g_normal);
	g_n1 = 1.01;
	g_n2 = GRT_OBJ.param_refract;
	g_n = g_n1 / g_n2;
	g_c2 = sqrt(1 - (g_n * g_n * (1 - (g_c1 * g_c1))));
	g_tmp = scalar_vector(g_n, RAY_DIRECTION);
	g_tmp2 = (g_n * g_c1 - g_c2);
	g_normal = scalar_vector(g_tmp2, &g_normal);
	g_rr = add_vector(&g_tmp, &g_normal);
	g_rr = normal_vector(g_rr);
	set_vector(RAY_ORIGIN, &g_point);
	set_vector(RAY_DIRECTION, &g_rr);
}

static inline void	reflection(t_rtv1 *rtv1)
{
	g_point = point_intersect(RT->ray, &g_t0);
	g_normal = get_intersect_normal(RT, g_num_obj, &g_point);
	g_normal.x += g_normal.x * 2;
	g_normal.y += g_normal.y * 2;
	g_normal.z += g_normal.z * 2;
	g_dir_point = normal_vector(sub_vector(RAY_DIRECTION, &g_normal));
	set_vector(RAY_ORIGIN, &g_point);
	set_vector(RAY_DIRECTION, &g_dir_point);
}

static inline void	main_component(t_rtv1 *rtv1, t_vector *origin,
	t_vector *dir, t_color color)
{
	set_vector(RAY_ORIGIN, origin);
	set_vector(RAY_DIRECTION, dir);
	g_depth++;
	while (++g_i < SIZE_OBJ)
	{
		g_t1 = 2000000.0f;
		g_hit = check_intersect_object(RT, &g_t1, g_i, RT->ray);
		if (g_hit != 0 && g_t1 < g_t0)
		{
			g_t0 = g_t1;
			g_num_obj = g_i;
		}
	}
}

t_color				recur(t_rtv1 *rtv1, t_vector *origin, t_vector *dir,
	t_color color)
{
	double		cos_i;

	g_i = -1;
	g_num_obj = -1;
	g_t0 = 2000000.0f;
	if (g_depth > OPTION->depth_rec)
		return (color);
	main_component(RT, origin, dir, color);
	if (g_num_obj == -1)
	{
		set_color(&color, BACKGROUND.red, BACKGROUND.blue, BACKGROUND.green);
		return (color);
	}
	else if (g_num_obj != -1 && OPTION->light_off_on == 1)
		color = ft_light(RT, &g_t0, g_num_obj);
	else if (g_num_obj != -1 && OPTION->light_off_on == 0)
		color = get_color(rtv1, g_num_obj);
	if (GRT_OBJ.id == SPHERE)
	{
		(GRT_OBJ.reflection == 1) ? reflection(RT) : 0;
		(GRT_OBJ.refraction == 1) ? refraction(RT) : 0;
		return (recur(rtv1, RAY_ORIGIN, RAY_DIRECTION, color));
	}
	return (color);
}

t_color				intersect(t_rtv1 *rtv1, int i)
{
	t_color color;

	if (OPTION->recursion == FALSE)
		color = fast_intersect(RT, i);
	else
	{
		color.red = 0;
		color.blue = 0;
		color.green = 0;
		g_depth = 0;
		color = recur(rtv1, RAY_ORIGIN, RAY_DIRECTION, color);
	}
	color.red = MIN(color.red * 255.0f, 255.0f);
	color.blue = MIN(color.blue * 255.0f, 255.0f);
	color.green = MIN(color.green * 255.0f, 255.0f);
	return (color);
}
