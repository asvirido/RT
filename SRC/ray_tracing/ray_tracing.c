/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:11:53 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:25:23 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void 	effect_filtres(t_rtv1 *rtv1)
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

void		ft_ssaa(t_rtv1 *rtv1, int i, t_color *res)
{
	t_color		color[OPTION->size_ssaa + 1];
	int			j;

	j = -1;
	printf("SSAA\n");
	res->red = 0;
	res->green = 0;
	res->blue = 0;
	while (++j < OPTION->size_ssaa)
	{
		set_vector(RAY_DIRECTION, &DIR_NORMAL);
		color[j] = intersect(rtv1);
	}
	midle_color(color, OPTION->size_ssaa, res);
}
#include <unistd.h>
void		just_rt(t_rtv1 *rtv1, int i, t_color *res)
{
	t_color		color;
	int			j;

	j = 0;
	color.red = 0;
	color.blue = 0;
	color.green = 0;
	// printf("Y x %f y %f z %f\n",DIR_NORMAL.x, DIR_NORMAL.y, DIR_NORMAL.z);
	// printf("R x %f y %f z %f\n",RAY_DIRECTION->x, RAY_DIRECTION->y, RAY_DIRECTION->z);
	// printf("P x %f y %f z %f\n",RT->pos->x, RT->pos->y, RT->pos->z);
	// printf("P %p\n", RT->pos);
	// printf("O %p/\n", RAY_ORIGIN);
	RAY_DIRECTION->x = DIR_NORMAL.x;
	RAY_DIRECTION->y = DIR_NORMAL.y;
	RAY_DIRECTION->z = DIR_NORMAL.z;
	RAY_ORIGIN->x = RT->pos->x;
	RAY_ORIGIN->y = RT->pos->y;
	RAY_ORIGIN->z = RT->pos->z;
	// set_vector(rtv1->ray->direction, &rtv1->screen[i].dir_ssaa[0]);
		// write(1, "ERROR!\n", 7);
		// printf("P %p\n", RT->pos);
	// set_vector(rtv1->ray->origin, rtv1->pos);
	// write(1, "ERROR!\n", 7);
	// printf("ERROR\n");
	if ((int)X % OPTION->draft_x == 0 && (int)Y % OPTION->draft_y == 0)
	{
		(OPTION->fov_on == TRUE ? fov(RT, X, Y) : 0);
		color = intersect(rtv1);
	}
	res->red = color.red;
	res->blue = color.blue;
	res->green = color.green;
}

void 	draw_rt(t_rtv1 *rtv1)
{
	int		i;

	i = -1;
	while (++i < OPTION->size_screen)
		put_img(rtv1->img, X, Y, RT->screen[i].color);
}

void	ray_tracing(t_rtv1 *rtv1)
{
	t_val_vector	val;
	int				i;

	mlx_clear_window(MLX_MY, WIN_MY);
	rtv1->img = create_img(rtv1->obj);
	i = -1;
	//set_vector(RT->pos, RAY_ORIGIN);
	while (++i < OPTION->size_screen)
	{
		// printf("r %f g %f b %f\n", RT->screen[i].color->red, RT->screen[i].color->green, RT->screen[i].color->blue);
		if (OPTION->ssaa == 1)
			ft_ssaa(RT, i, RT->screen[i].color);
		else if (OPTION->ssaa == 0)
			just_rt(RT, i, RT->screen[i].color);
	}
	printf("r\n" );
	if (OPTION->motion_blur == TRUE)
		motion_blur(RT);
	if (OPTION->filters == TRUE)
		effect_filtres(RT);
	draw_rt(RT);
	PUT_IMG_WIN(MLX_MY, WIN_MY, rtv1->img->img, 0, 0);
	printf("END\n");
	free(rtv1->img);
}
