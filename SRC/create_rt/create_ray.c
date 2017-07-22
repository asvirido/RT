/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:48:27 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/29 19:48:28 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_rt.h"

t_ray	*create_ray(void)
{
	t_ray		*ray;

	ray = (t_ray*)malloc(sizeof(t_ray) + 1);
	ray->origin = create_vector();
	ray->direction = create_vector();
	return (ray);
}
