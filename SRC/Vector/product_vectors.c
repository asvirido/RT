/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product_vectors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:47:20 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/23 18:47:20 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	product_vectors(t_vector *a, t_vector *b)
{
	t_vector	c;

	c.x = (a->y * b->z) - (a->z * b->y);
	c.y = (a->x * b->z) - (a->z * b->x);
	c.z = (a->x * b->y) - (a->y * b->x);
	return (c);
}
