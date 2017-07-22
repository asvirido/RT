/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkachyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:23:50 by otkachyk          #+#    #+#             */
/*   Updated: 2017/07/20 15:23:52 by otkachyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void				*thread_draw2(void *parameter)
{
	int		x;
	int		y;
	t_rtv1	*rtv1;

	rtv1 = (t_rtv1*)parameter;
	x = 0;
	y = OPTION->size_y / 2;
	while (y < OPTION->size_y)
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

void				*thread_draw3(void *parameter)
{
	int		x;
	int		y;
	t_rtv1	*rtv1;

	rtv1 = (t_rtv1*)parameter;
	x = 0;
	y = OPTION->size_y / 2;
	while (y < OPTION->size_y)
	{
		x = OPTION->size_x / 2;
		while (x < OPTION->size_x)
		{
			x++;
			put_img(rtv1->img, x, y, RT->screen[x + y * OPTION->size_x].color);
		}
		y++;
	}
	return (0);
}

void				*thread_draw4(void *parameter)
{
	int		x;
	int		y;
	t_rtv1	*rtv1;

	rtv1 = (t_rtv1*)parameter;
	x = 0;
	y = 0;
	while (y < OPTION->size_y / 2)
	{
		x = OPTION->size_x / 2;
		while (x < OPTION->size_x)
		{
			x++;
			put_img(rtv1->img, x, y, RT->screen[x + y * OPTION->size_x].color);
		}
		y++;
	}
	return (0);
}

static inline void	thread(t_rtv1 *rtv1, int ret, int ret2,
	pthread_t *thread_handle)
{
	ret = pthread_create(&thread_handle[0], 0, thread_draw1, (void*)rtv1);
	if (ret != 0)
	{
		printf("ERROR %d\n", ret);
		exit(1);
	}
	ret2 = pthread_create(&thread_handle[1], 0, thread_draw2, (void*)rtv1);
	if (ret2 != 0)
	{
		printf("ERROR %d\n", ret);
		exit(1);
	}
	ret2 = pthread_create(&thread_handle[2], 0, thread_draw3, (void*)rtv1);
	if (ret2 != 0)
	{
		printf("ERROR %d\n", ret);
		exit(1);
	}
	ret2 = pthread_create(&thread_handle[3], 0, thread_draw4, (void*)rtv1);
	if (ret2 != 0)
	{
		printf("ERROR %d\n", ret);
		exit(1);
	}
}

void				draw_rt(t_rtv1 *rtv1)
{
	pthread_t	thread_handle[4];
	int			ret;
	int			ret2;

	thread(rtv1, ret, ret2, thread_handle);
	pthread_join(thread_handle[0], 0);
	pthread_join(thread_handle[1], 0);
	pthread_join(thread_handle[2], 0);
	pthread_join(thread_handle[3], 0);
}
