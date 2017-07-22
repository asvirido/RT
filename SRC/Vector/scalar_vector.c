/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 19:23:31 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:27:32 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	scalar_vector(double c, t_vector *a)
{
	t_vector	new;

	new.x = a->x * c;
	new.y = a->y * c;
	new.z = a->z * c;
	return (new);
}
