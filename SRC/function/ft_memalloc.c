/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:43:27 by asvirido          #+#    #+#             */
/*   Updated: 2017/07/13 17:43:27 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	*ft_memalloc(size_t size)
{
	char *str;

	str = malloc(size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return ((void*)str);
}
