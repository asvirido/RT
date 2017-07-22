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

int		event_camera(int k, t_rtv1 *rtv1)
{
	if (k == 126)
		move_forward_camera(rtv1);
	else if (k == 125)
		move_back_camera(rtv1);
	else if (k == 123)
		move_right_camera(rtv1);
	else if (k == 124)
		move_left_camera(rtv1);
	else if (k == 69)
		move_up_camera(rtv1);
	else if (k == 78)
		move_down_camera(rtv1);
	else if (k == 16 || k == 4)
		rotation_x(rtv1, k);
	else if (k == 13 || k == 1)
		rotation_y(rtv1, k);
	else if (k == 0 || k == 2)
		rotation_z(rtv1, k);
	if (k == 126 || k == 125 || k == 123 || k == 124 || k == 69 || k == 78
		|| k == 16 || k == 4 || k == 13 || k == 1 || k == 0 || k == 2)
		ray_tracing(RT);
	return (1);
}
