/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_size_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:51:15 by asvirido          #+#    #+#             */
/*   Updated: 2017/07/08 16:51:16 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_src.h"

int		valid_size_win_one(int size_x, int size_y)
{
	if (size_x == 320 && size_y == 240)
		return (1);
	else if (size_x == 352 && size_y == 240)
		return (1);
	else if (size_x == 352 && size_y == 288)
		return (1);
	else if (size_x == 400 && size_y == 240)
		return (1);
	else if (size_x == 480 && size_y == 576)
		return (1);
	else if (size_x == 640 && size_y == 240)
		return (1);
	else if (size_x == 320 && size_y == 480)
		return (1);
	else if (size_x == 640 && size_y == 360)
		return (1);
	else if (size_x == 640 && size_y == 480)
		return (1);
	else if (size_x == 800 && size_y == 480)
		return (1);
	else if (size_x == 800 && size_y == 600)
		return (1);
	return (0);
}

int		valid_size_win_two(int size_x, int size_y)
{
	if (size_x == 848 && size_y == 486)
		return (1);
	else if (size_x == 960 && size_y == 540)
		return (1);
	else if (size_x == 1024 && size_y == 600)
		return (1);
	else if (size_x == 1024 && size_y == 768)
		return (1);
	else if (size_x == 1152 && size_y == 864)
		return (1);
	else if (size_x == 1200 && size_y == 600)
		return (1);
	else if (size_x == 1280 && size_y == 720)
		return (1);
	else if (size_x == 1280 && size_y == 768)
		return (1);
	else if (size_x == 1280 && size_y == 1024)
		return (1);
	else if (size_x == 1440 && size_y == 900)
		return (1);
	else if (size_x == 1400 && size_y == 1050)
		return (1);
	else if (size_x == 1920 && size_y == 1200)
		return (1);
	return (0);
}

int		valid_size_win_three(int size_x, int size_y)
{
	if (size_x == 1500 && size_y == 1024)
		return (1);
	else if (size_x == 1536 && size_y == 960)
		return (1);
	else if (size_x == 1536 && size_y == 1024)
		return (1);
	else if (size_x == 1600 && size_y == 900)
		return (1);
	else if (size_x == 1600 && size_y == 1024)
		return (1);
	else if (size_x == 1600 && size_y == 1200)
		return (1);
	else if (size_x == 1680 && size_y == 1050)
		return (1);
	else if (size_x == 1920 && size_y == 1080)
		return (1);
	return (0);
}

void	valid_size_win(int size_x, int size_y)
{
	if ((valid_size_win_one(size_x, size_y)) == 1)
		return ;
	else if ((valid_size_win_two(size_x, size_y)) == 1)
		return ;
	else if ((valid_size_win_three(size_x, size_y)) == 1)
		return ;
	printf("ERROR: Bad weight or height\n");
	exit(1);
}
