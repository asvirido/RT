/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:30:53 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:34:26 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_src.h"

void	set_color(t_color *color, double red, double green, double blue)
{
	color->red = red;
	color->blue = green;
	color->green = blue;
}
