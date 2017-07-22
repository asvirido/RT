/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midle_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:58:44 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:32:02 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_src.h"

void	midle_color(t_color *array, int size, t_color *new)
{
	int		i;

	i = 0;
	set_color(new, 0, 0, 0);
	while (i < size)
	{
		new->red += array[i].red;
		new->blue += array[i].blue;
		new->green += array[i].green;
		i++;
	}
	new->red /= size;
	new->blue /= size;
	new->green /= size;
}
