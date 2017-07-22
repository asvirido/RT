/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_and_white.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:34:33 by asvirido          #+#    #+#             */
/*   Updated: 2017/06/17 16:34:33 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_src.h"

t_color		black_and_white(t_color old)
{
	t_color	new;
	double	gray;

	gray = (old.red + old.green + old.blue) / 3;
	new.red = gray;
	new.blue = gray;
	new.green = gray;
	return (new);
}
