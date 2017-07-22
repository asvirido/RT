/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_use.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 23:29:30 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/21 23:29:30 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	mlx_use(t_rtv1 *rtv1)
{
	mlx_key_hook(WIN_MY, event_key, rtv1);
	mlx_hook(WIN_MY, 2, 5, event_camera, rtv1);
	mlx_mouse_hook(WIN_MY, event_mouse, rtv1);
	mlx_hook(WIN_MY, 17, 0, destroy, 0);
	mlx_loop(MLX_MY);
}
