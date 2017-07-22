/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 05:58:10 by asvirido          #+#    #+#             */
/*   Updated: 2017/07/20 05:58:11 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	valid_filters(t_rtv1 *rtv1)
{
	int		size;

	size = 0;
	if (OPTION->sepia == TRUE)
		size++;
	if (OPTION->black_and_white == TRUE)
		size++;
	if (OPTION->darkroom == TRUE)
		size++;
	if (size > 1)
		error_exit("ERROR$1: too many filters");
	if (OPTION->filters == FALSE && size == 1)
		error_exit("ERROR: filters == FALSE and to many filters");
	if (OPTION->filters == TRUE && size == 0)
		error_exit("ERROR$7: filters == TRUE and too small filters");
}

void	valid_size_ssaa(t_rtv1 *rtv1)
{
	if (OPTION->ssaa == TRUE)
	{
		if (OPTION->size_ssaa <= 0)
			error_exit("ERROR$4: too small size SSAA; size ssaa[1,2,4,8]");
		if (OPTION->size_ssaa != 2 && OPTION->size_ssaa != 1)
			if (OPTION->size_ssaa != 4 && OPTION->size_ssaa != 8)
				error_exit("ERROR$3: too big size SSAA; size ssaa[1,2,4,8]");
	}
}

void	valid_light(t_rtv1 *rtv1)
{
	int size;

	size = 0;
	(OPTION->lambert_light == TRUE ? size += 1 : 0);
	(OPTION->blinn_fong == TRUE ? size += 1 : 0);
	(OPTION->cel_shaded == TRUE ? size += 1 : 0);
	(OPTION->view_point == TRUE ? size += 1 : 0);
	(OPTION->view_normal == TRUE ? size += 1 : 0);
	if (size > 1)
		error_exit("ERROR$5: too many model light:)");
}

void	valid_antialiasing(t_rtv1 *rtv1)
{
	int size;

	size = 0;
	(OPTION->ssaa == TRUE ? size += 1 : 0);
	(OPTION->fxaa == TRUE ? size += 1 : 0);
	if (size > 1)
		error_exit("ERROR$2: too many ANTI_ALIASING");
	if (OPTION->fxaa == TRUE && OPTION->motion_blur != FALSE)
	{
		OPTION->motion_blur = TRUE;
		OPTION->size_blur = 4;
	}
	if (OPTION->ssaa == FALSE)
		OPTION->size_ssaa = 1;
	if (OPTION->size_blur <= 0)
		error_exit("ERROR$4: too small size Motion Blur; size_blur[1-49]");
	if (OPTION->size_blur >= 50)
		error_exit("ERROR$6: too big size Motion Blur; size_blur[1-49]");
	valid_size_ssaa(RT);
}

void	valid_option(t_rtv1 *rtv1)
{
	valid_filters(RT);
	OPTION->size_screen = OPTION->size_x * OPTION->size_y;
	valid_antialiasing(RT);
	valid_light(RT);
	if (OPTION->speed <= 0 || OPTION->speed >= 1000)
		error_exit("ERRRO12 camera speed[1-999]");
	if (OPTION->ssaa || OPTION->fxaa || OPTION->motion_blur)
	{
		if (OPTION->draft_x != 1 && OPTION->draft_y != 1)
			error_exit("Sorry: ERROR$8 draft dont work");
	}
	if (OPTION->draft_x < 1 || OPTION->draft_x > 5)
		error_exit("ERROR$9 draft_x{1-5}");
	if (OPTION->draft_y < 1 || OPTION->draft_y > 5)
		error_exit("ERROR$10 draft_y{1-5}");
}
