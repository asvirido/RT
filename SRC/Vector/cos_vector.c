/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cos_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:30:23 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:25:29 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double		cos_vector(t_vector *a, t_vector *b)
{
	double	module_a;
	double	module_b;
	double	scalar_product;
	double	angle;

	module_a = module_vector(a);
	module_b = module_vector(b);
	scalar_product = dot_vector(a, b);
	angle = scalar_product / (module_a * module_b);
	return (angle);
}
