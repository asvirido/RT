/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:42:21 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:34:04 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_src.h"

t_color		create_color(int color)
{
	t_color		new;
	int			red;
	int			blue;
	int			green;

	red = (color >> 16);
	green = (color >> 8) - (red << 8);
	blue = (color) - (red << 16) - (green << 8);
	new.red = red;
	new.green = green;
	new.blue = blue;
	return (new);
}
