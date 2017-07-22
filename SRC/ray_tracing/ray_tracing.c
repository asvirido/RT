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

void				just_rt(t_rtv1 *rtv1, int i, t_color *res)
{
	t_color		color;
	int			j;

	j = 0;
	color.red = 0;
	color.blue = 0;
	color.green = 0;
	set_vector(RAY_DIRECTION, &DIR_NORMAL);
	set_vector(RAY_ORIGIN, RT->pos);
	if ((int)X % OPTION->draft_x == 0 && (int)Y % OPTION->draft_y == 0)
	{
		set_vector(RAY_DIRECTION, &DIR_NORMAL);
		color = intersect(rtv1, i);
	}
	res->red = color.red;
	res->blue = color.blue;
	res->green = color.green;
}

void				horizont(t_rtv1 *rtv1)
{
	int			i;

	i = -1;
	while (++i < OPTION->size_screen)
	{
		if (i + 1 < OPTION->size_screen && i - 1 >= 0 &&
			i + OPTION->size_x < OPTION->size_screen)
		{
			if (RT->screen[i + 1].id == RT->screen[i].id
				&& RT->screen[i - 1].id == RT->screen[i].id
				&& RT->screen[i + OPTION->size_x].id == RT->screen[i].id)
			{
				RT->screen[i].w = 1;
			}
			else
				RT->screen[i].w = 0;
		}
	}
}

static inline void	main_while(t_rtv1 *rtv1, int i)
{
	while (++i < OPTION->size_screen)
	{
		RT->count++;
		if (RT->count == RT->procent_one)
		{
			RT->loading_progress++;
			RT->count = 0;
			printf("\r%s%s%d%s%s", GREEN, "Loading ",
				RT->loading_progress, "%", RESET);
			fflush(stdout);
		}
		if (OPTION->ssaa == 1)
			ft_ssaa(RT, i, RT->screen[i].color);
		else if (OPTION->ssaa == 0)
			just_rt(RT, i, RT->screen[i].color);
	}
}

static inline void	main_component(t_rtv1 *rtv1)
{
	if (OPTION->motion_blur == TRUE)
		motion_blur(RT);
	if (OPTION->filters == TRUE)
		effect_filtres(RT);
	if (OPTION->horizont == TRUE)
	{
		horizont(RT);
		if (OPTION->carton == TRUE)
			carton(RT);
		else if (OPTION->outline == TRUE)
			outline(RT);
	}
}

void				ray_tracing(t_rtv1 *rtv1)
{
	t_val_vector	val;
	int				i;

	mlx_clear_window(MLX_MY, WIN_MY);
	rtv1->img = create_img(rtv1->obj);
	system("clear");
	i = -1;
	RT->count = 0;
	RT->loading_progress = 0;
	main_while(rtv1, i);
	main_component(rtv1);
	draw_rt(RT);
	PUT_IMG_WIN(MLX_MY, WIN_MY, rtv1->img->img, 0, 0);
	free(rtv1->img);
}
