/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:35:49 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:02:15 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

void	rotation_x_cam(t_rtv1 *rtv1, double angle)
{
	int			i;
	int			j;
	double		y;
	double		z;

	i = -1;
	while (++i < OPTION->size_screen)
	{
		j = -1;
		while (++j < OPTION->size_ssaa)
		{
			y = DIR_NORMAL.y * cos(angle) - DIR_NORMAL.z * sin(angle);
			z = DIR_NORMAL.y * sin(angle) + DIR_NORMAL.z * cos(angle);
			DIR_NORMAL.y = y;
			DIR_NORMAL.z = z;
		}
	}
}

void	rotation_x(t_rtv1 *rtv1, int keycode)
{
	if (keycode == 16)
		rotation_x_cam(rtv1, 5 * RAD);
	else if (keycode == 4)
		rotation_x_cam(rtv1, -5 * RAD);
}
