/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:42:06 by asvirido          #+#    #+#             */
/*   Updated: 2017/01/26 16:15:47 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_src.h"

t_mlx	*object_mlx(int size_x, int size_y, char *name)
{
	t_mlx		*new;

	if (name == NULL)
	{
		printf("ERROR! Bad name window\n");
		exit(1);
	}
	valid_size_win(size_x, size_y);
	new = (t_mlx*)malloc(sizeof(t_mlx));
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, size_x, size_y, name);
	new->size_x = size_x;
	new->size_y = size_y;
	return (new);
}
