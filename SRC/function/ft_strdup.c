/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:19:45 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/01 21:42:03 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*buf;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	if (!(buf = (char*)malloc(len + 1)))
		return (NULL);
	while (s1[i])
	{
		buf[i] = s1[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
