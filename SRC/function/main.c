/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:14:08 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 21:31:52 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	*ft_copy(void *data, size_t size)
{
	void	*shit;

	shit = malloc(size);
	memcpy(shit, data, size);
	return (shit);
}

int		main(int argc, char **argv)
{
	t_rtv1		*rtv1;
	t_env		*e;

	if (argc != 2)
		error_exit("bad param");
	e = (t_env*)malloc(sizeof(t_env));
	rtv1 = create_rtv1(e, argv[1]);
	ray_tracing(rtv1);
	mlx_use(rtv1);
	return (0);
}
