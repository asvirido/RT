/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:47:44 by asvirido          #+#    #+#             */
/*   Updated: 2017/02/06 17:47:45 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

void	rotation_y_cam(t_rtv1 *rtv1, int angle)
{
	int			i;
	double		x;
	double		z;

	i = -1;
	while (++i < SIZE)
	{
		x = DIR_NORMAL->x * cos(angle * RAD) + DIR_NORMAL->z * sin(angle * RAD);
		z = -DIR_NORMAL->x * sin(angle * RAD) + DIR_NORMAL->z * cos(angle * RAD);
		DIR_NORMAL->x = x;
		DIR_NORMAL->z = z;
	}
}

void	rotation_y(t_rtv1 *rtv1, int keycode)
{
	if (keycode == BUTTON_W)
		rotation_y_cam(rtv1, 1);
	else if (keycode == BUTTON_S)
		rotation_y_cam(rtv1, -1);
}
