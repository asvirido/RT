/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 16:38:34 by asvirido          #+#    #+#             */
/*   Updated: 2017/06/22 16:38:35 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	rot_z(t_vector *v, int angle)
{
	double	x;
	double	y;

	x = v->x * cos(angle * RAD) - v->y * sin(angle * RAD);
	y = v->x * sin(angle * RAD) + v->y * cos(angle * RAD);
	v->x = x;
	v->y = y;
}

void	rot_y(t_vector *v, int angle)
{
	double	x;
	double	z;

	x = v->x * cos(angle * RAD) - v->z * sin(angle * RAD);
	z = v->x * sin(angle * RAD) + v->z * cos(angle * RAD);
	v->x = x;
	v->z = z;
}

void	rot_x(t_vector *v, int angle)
{
	double	y;
	double	z;

	y = v->y * cos(angle * RAD) - v->z * sin(angle * RAD);
	z = v->y * sin(angle * RAD) + v->z * cos(angle * RAD);
	v->y = y;
	v->z = z;
}

void	rotation_vector(t_vector *a, t_vector *rotation)
{
	if (rotation->x != 0)
		rot_x(a, rotation->x);
	if (rotation->y != 0)
		rot_y(a, rotation->y);
	if (rotation->z != 0)
		rot_z(a, rotation->z);
}
