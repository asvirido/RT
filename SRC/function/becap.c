/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   becap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 05:14:02 by asvirido          #+#    #+#             */
/*   Updated: 2017/07/20 05:14:04 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	saveppm(char *filename, unsigned char *img, int width, int height)
{
	FILE *f;

	f = fopen(filename, "w");
	fprintf(f, "P6 %d %d %d\n", width, height, 255);
	fwrite(img, 3, width * height, f);
	fclose(f);
}

void	becap(t_rtv1 *rtv1)
{
	unsigned char	img[OPTION->size_x * OPTION->size_y * 3];
	int				i;
	int				y;
	int				x;
	int				size;

	y = -1;
	while (++y < OPTION->size_y)
	{
		x = -1;
		while (++x < OPTION->size_x)
		{
			size = x + y * OPTION->size_x;
			img[size * 3 + 0] = RT->screen[y * OPTION->size_x + x].color->red;
			img[size * 3 + 1] = RT->screen[y * OPTION->size_x + x].color->green;
			img[size * 3 + 2] = RT->screen[y * OPTION->size_x + x].color->blue;
		}
	}
	saveppm("RT.ppm", img, OPTION->size_x, OPTION->size_y);
}
