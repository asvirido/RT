/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:44:13 by asvirido          #+#    #+#             */
/*   Updated: 2017/02/09 16:44:16 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_rt.h"

t_screen	*create_map(int size_x, int size_y)
{
	t_screen	*new;
	int			y;
	int			i;
	int			x;

	i = 0;
	y = 0;
	x = 0;
	new = (t_screen*)malloc(sizeof(t_screen) * (size_x * size_y) + 1);
	while (y < size_y)
	{
		new[i].ray = create_vector();
		new[i].color = (t_color*)malloc(sizeof(t_color) + 1);
		new[i].color->red = 0;
		new[i].color->blue = 0;
		new[i].color->green = 0;
		(x == size_x ? y += 1 : 0);
		(x == size_x ? x = 0 : 0);
		new[i].ray->x = x;
		new[i].ray->y = y;
		new[i].ray->z = 0.99;
		x++;
		i++;
	}
	return (new);
}
