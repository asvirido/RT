/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 23:16:11 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/21 23:16:11 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	ft_migr(t_rtv1 *rtv1, int keycode)
{
	if (keycode == 126)
		move_forward_camera(rtv1);
	else if (keycode == 125)
		move_back_camera(rtv1);
	else if (keycode == 123)
		move_right_camera(rtv1);
	else if (keycode == 124)
		move_left_camera(rtv1);
	else if (keycode == 69)
		move_down_camera(rtv1);
	else if (keycode == 78)
		move_up_camera(rtv1);
	else if (keycode == 16 || keycode == 4)
		rotation_x(rtv1, keycode);
	else if (keycode == 13 || keycode == 1)
		rotation_y(rtv1, keycode);
	else if (keycode == 0 || keycode == 2)
		rotation_z(rtv1, keycode);
	ray_tracing(rtv1);
}

int		event_camera(int keycode, t_rtv1 *rt)
{
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124
		|| keycode == 69 || keycode == 78 || keycode == 4 || keycode == 16
		|| keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		ft_migr(rt, keycode);
	return (1);
}
