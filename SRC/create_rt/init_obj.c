/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 22:39:27 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/18 18:09:44 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	parcing_light_ambient(t_rtv1 *rtv1)
{
	int		i;

	i = -1;
	while (++i < SIZE_LIGHT)
	{
		L.color.red *= 0.00255;
		L.color.blue *= 0.00255;
		L.color.green *= 0.00255;
		L.ambient = (L.color.red + L.color.green + L.color.blue) / 3;
	}
}

void	parcing_light_position(t_rtv1 *rtv1)
{
	int		i;

	i = -1;
	while (++i < SIZE_LIGHT)
	{
		L.position.x += 0.99;
		L.position.y += 0.99;
		L.position.z += 0.99;
	}
}

void	parcing_rotation(t_rtv1 *rtv1)
{
	int	num_obj;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
		rotation_vector(&RT_OBJ.direction, &RT_OBJ.rotation);
}

void	parcing_direction_two(t_rtv1 *rtv1)
{
	int	num_obj;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
	{
		if (RT_OBJ.id == SPHERE)
			continue ;
		if (RT_OBJ.direction.x == 0)
			if (RT_OBJ.direction.y == 0 && RT_OBJ.direction.z == 0)
			{
				printf("Bad direction: num object %d\n", num_obj + 1);
				exit(1);
			}
	}
}

void	init_demo(t_rtv1 *rtv1)
{
	parsing_color(RT);
	parcing_size_pow(RT);
	parsing_direction(RT);
	parcing_direction_two(RT);
	parcing_cone(RT);
	parcing_half_sphere(RT);
	parcing_light_ambient(RT);
	parcing_light_position(RT);
	parcing_rotation(RT);
	parcing_shines(RT);
	parcing_reftact(RT);
}
