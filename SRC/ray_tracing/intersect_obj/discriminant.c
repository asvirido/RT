/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:38:08 by asvirido          #+#    #+#             */
/*   Updated: 2017/04/28 13:38:09 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../head.h"

int		discriminant(double *t, t_val_math val)
{
	val.d = val.b * val.b - 4 * val.a * val.c;
	if (val.d < 0)
		return (0);
	val.c = sqrtf(val.d);
	val.t0 = (-val.b + val.c) / (2 * val.a);
	val.t1 = (-val.b - val.c) / (2 * val.a);
	if (val.t0 < MINIMUM && val.t1 < MINIMUM)
		return (0);
	else if (val.t0 > MINIMUM && val.t1 > MINIMUM && val.t0 > val.t1)
		val.t0 = val.t1;
	else if (val.t0 < MINIMUM)
		val.t0 = val.t1;
	if (val.t0 > MINIMUM)
	{
		*t = val.t0;
		return (1);
	}
	return (0);
}
