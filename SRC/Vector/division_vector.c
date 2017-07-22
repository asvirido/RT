/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 21:39:42 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:23:20 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	division_vector(t_vector *v, double a)
{
	t_vector	new;

	new.x = v->x / a;
	new.y = v->y / a;
	new.z = v->z / a;
	return (new);
}
