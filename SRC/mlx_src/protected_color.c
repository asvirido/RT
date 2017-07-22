/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:54:38 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:31:27 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_src.h"

void	protected_color(t_color *color)
{
	if (color->red >= 1)
		color->red = 1;
	if (color->blue >= 1)
		color->blue = 1;
	if (color->green >= 1)
		color->green = 1;
	if (color->red <= 0)
		color->red = 0;
	if (color->blue <= 0)
		color->blue = 0;
	if (color->green <= 0)
		color->green = 0;
}
