/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkachyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:24:02 by otkachyk          #+#    #+#             */
/*   Updated: 2017/07/20 15:24:06 by otkachyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	effect_filtres(t_rtv1 *rtv1)
{
	int		i;
	t_color	color;

	i = -1;
	while (++i < OPTION->size_screen)
	{
		if (OPTION->sepia == TRUE)
			color = sepia(*RT->screen[i].color);
		else if (OPTION->black_and_white == TRUE)
			color = black_and_white(*RT->screen[i].color);
		else if (OPTION->darkroom == TRUE)
			color = darkroom(*RT->screen[i].color);
		else
			continue ;
		RT->screen[i].color->red = color.red;
		RT->screen[i].color->blue = color.blue;
		RT->screen[i].color->green = color.green;
	}
}

void	ft_ssaa(t_rtv1 *rtv1, int i, t_color *res)
{
	t_color		color[OPTION->size_ssaa + 1];
	int			j;

	j = -1;
	res->red = 0;
	res->green = 0;
	res->blue = 0;
	while (++j < OPTION->size_ssaa)
	{
		set_vector(RAY_ORIGIN, RT->pos);
		set_vector(RAY_DIRECTION, &DIR_NORMAL);
		color[j] = intersect(rtv1, i);
	}
	midle_color(color, OPTION->size_ssaa, res);
}

void	carton(t_rtv1 *rtv1)
{
	int		i;

	i = -1;
	while (++i < OPTION->size_screen)
	{
		if (RT->screen[i].w == 1)
		{
			RT->screen[i].color->red = 255;
			RT->screen[i].color->green = 255;
			RT->screen[i].color->blue = 255;
		}
		else if (RT->screen[i].w == 0)
		{
			RT->screen[i].color->red = 0;
			RT->screen[i].color->blue = 0;
			RT->screen[i].color->green = 0;
		}
	}
}

void	outline(t_rtv1 *rtv1)
{
	int		i;

	i = -1;
	while (++i < OPTION->size_screen)
	{
		if (RT->screen[i].ray->y + 1 == OPTION->size_y)
			continue ;
		if (RT->screen[i].ray->x + 1 == OPTION->size_x)
			continue ;
		if (RT->screen[i].w == 0)
		{
			RT->screen[i].color->red = OPTION->outline_color.red;
			RT->screen[i].color->blue = OPTION->outline_color.blue;
			RT->screen[i].color->green = OPTION->outline_color.green;
		}
	}
}

void	*thread_draw1(void *parameter)
{
	int		x;
	int		y;
	t_rtv1	*rtv1;

	rtv1 = (t_rtv1*)parameter;
	x = 0;
	y = 0;
	while (y < OPTION->size_y / 2)
	{
		x = 0;
		while (x < OPTION->size_x / 2)
		{
			x++;
			put_img(rtv1->img, x, y, RT->screen[x + y * OPTION->size_x].color);
		}
		y++;
	}
	return (0);
}
