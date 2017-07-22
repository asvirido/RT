/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:55:59 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/10 03:26:25 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*create_vector(void)
{
	t_vector	*new;

	new = (t_vector*)malloc(sizeof(t_vector));
	new->x = 0;
	new->y = 0;
	new->z = 0;
	return (new);
}
