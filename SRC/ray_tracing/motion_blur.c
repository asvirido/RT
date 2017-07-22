/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_blur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 16:24:14 by asvirido          #+#    #+#             */
/*   Updated: 2017/07/09 16:24:15 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	motion_blur(t_rtv1 *rtv1)
{
	int			i;
	int			k;
	int			y;
	int			len;
	t_color		blur[OPTION->size_blur + 1];

	i = -1;
	while (++i < OPTION->size_screen)
	{
		k = -1;
		y = RT->screen[i].ray->y;
		while (++k < OPTION->size_blur)
		{
			len = i + k;
			if (len >= OPTION->size_screen || RT->screen[len].ray->y != y)
				len = i;
			blur[k].red = RT->screen[len].color->red;
			blur[k].green = RT->screen[len].color->green;
			blur[k].blue = RT->screen[len].color->blue;
		}
		midle_color(blur, k, RT->screen[i].color);
	}
}
