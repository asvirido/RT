/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darkroom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:34:21 by asvirido          #+#    #+#             */
/*   Updated: 2017/06/17 16:34:22 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_src.h"

t_color		darkroom(t_color a)
{
	t_color		new;

	new.red = (a.red * 0.99) + (a.green * 0.99) + (a.blue * 0.99);
	new.green = (a.red + a.green + a.blue) / 150;
	new.blue = (a.red + a.green + a.blue) / 150;
	new.red = (new.red + new.green + new.blue) / 3;
	if (new.red >= 255)
		new.red = 255;
	if (new.green >= 255)
		new.green = 255;
	if (new.blue >= 255)
		new.blue = 255;
	return (new);
}
