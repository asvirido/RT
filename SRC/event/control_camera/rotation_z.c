/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:48:00 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:11:01 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

void	rotation_z_cam(t_rtv1 *rtv1, double angle)
{
	int			i;
	int			j;
	double		y;
	double		x;

	i = -1;
	while (++i < OPTION->size_screen)
	{
		j = -1;
		while (++j < OPTION->size_ssaa)
		{
			x = DIR_NORMAL.x * cos(angle) + DIR_NORMAL.y * sin(angle);
			y = -DIR_NORMAL.x * sin(angle) + DIR_NORMAL.y * cos(angle);
			DIR_NORMAL.x = x;
			DIR_NORMAL.y = y;
		}
	}
}

void	rotation_z(t_rtv1 *rtv1, int keycode)
{
	if (keycode == BUTTON_A)
		rotation_z_cam(rtv1, 5 * RAD);
	else if (keycode == BUTTON_D)
		rotation_z_cam(rtv1, -5 * RAD);
}
