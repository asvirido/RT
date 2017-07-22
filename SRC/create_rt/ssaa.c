/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssaa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 16:17:40 by asvirido          #+#    #+#             */
/*   Updated: 2017/07/07 16:17:40 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

static t_vector		add(t_vector a, float b, float c)
{
	t_vector res;

	res.x = a.x + b;
	res.y = a.y + c;
	res.z = a.z;
	return (res);
}

static t_vector		x2_anti_alias(t_vector temp, int j)
{
	if (j == 1)
		temp = add(temp, 0, -0.5);
	else if (j == 2)
		temp = add(temp, 0, 0.5);
	return (temp);
}

static t_vector		x4_anti_alias(t_vector temp, int j)
{
	if (j == 1 || j == 5)
		temp = add(temp, 0.25, 0.25);
	else if (j == 2 || j == 6)
		temp = add(temp, 0.25, -0.25);
	else if (j == 3)
		temp = add(temp, -0.25, 0.25);
	else if (j == 4)
		temp = add(temp, -.25, -0.25);
	return (temp);
}

static t_vector		x8_anti_alias(t_vector temp, int j)
{
	if (j <= 2)
		temp = x2_anti_alias(temp, j);
	if (j >= 3 && j <= 6)
		temp = x4_anti_alias(temp, j);
	if (j == 7)
		temp = add(temp, -0.5, 0);
	if (j == 8)
		temp = add(temp, 0.5, 0);
	return (temp);
}

t_vector			calc_ssaa(t_rtv1 *rtv1, t_vector *dir, int j)
{
	t_vector res;
	t_vector temp;

	temp = sub_vector(dir, RAY_ORIGIN);
	if (OPTION->size_ssaa == 2)
		temp = x2_anti_alias(temp, j);
	if (OPTION->size_ssaa == 4)
		temp = x4_anti_alias(temp, j);
	if (OPTION->size_ssaa == 8)
		temp = x8_anti_alias(temp, j);
	res = normal_vector(temp);
	return (res);
}
