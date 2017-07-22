/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkachyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:39:50 by otkachyk          #+#    #+#             */
/*   Updated: 2017/07/21 15:39:50 by otkachyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	ft_check_objtype(char *str, t_all_data *data, int i)
{
	if (!str)
		ft_pars_err("Object type error");
	else if (strcmp(str, "Sphere") == 0)
		data->all_obj[i].id = SPHERE;
	else if (strcmp(str, "Plane") == 0)
		data->all_obj[i].id = PLANE;
	else if (strcmp(str, "Cone") == 0)
		data->all_obj[i].id = CONE;
	else if (strcmp(str, "Cylinder") == 0)
		data->all_obj[i].id = CYLINDER;
	else if (strcmp(str, "Disc") == 0)
		data->all_obj[i].id = DISC;
	else if (strcmp(str, "Half_sphere") == 0)
		data->all_obj[i].id = HALF_SPHERE;
	else if (strcmp(str, "Ellipsoid") == 0)
		data->all_obj[i].id = ELLIPSOID;
	else if (strcmp(str, "Cd_disc") == 0)
		data->all_obj[i].id = CD_DISC;
	else
		ft_pars_err("Object type error");
}

void	ft_parse_opt(t_json_obj *j, t_all_data *data, int i)
{
	j->j_object = cJSON_GetArrayItem(j->j_format, i);
	j->j_type = cJSON_GetObjectItemCaseSensitive(j->j_object, "type");
	if (!cJSON_IsString(j->j_type))
		ft_pars_err("Obect type error");
	ft_check_objtype(j->j_type->valuestring, data, i);
	data->all_obj[i].type = j->j_type->valuestring;
	j->j_size = cJSON_GetObjectItemCaseSensitive(j->j_object, "size");
	if (!cJSON_IsNumber(j->j_size))
		ft_pars_err("Size parameters error");
	data->all_obj[i].size = j->j_size->valuedouble;
}

void	parsing_color(t_rtv1 *rtv1)
{
	int		num_obj;

	num_obj = -1;
	BACKGROUND.red *= 0.00255;
	BACKGROUND.green *= 0.00255;
	BACKGROUND.blue *= 0.00255;
	while (++num_obj < SIZE_OBJ)
	{
		RT_OBJ.color.red *= 0.00255;
		RT_OBJ.color.blue *= 0.00255;
		RT_OBJ.color.green *= 0.00255;
	}
}

void	parsing_direction(t_rtv1 *rtv1)
{
	int			num_obj;
	t_vector	tmp;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
	{
		tmp = normal_vector(RT_OBJ.direction);
		set_vector(&RT_OBJ.direction, &tmp);
	}
}

void	parcing_size_pow(t_rtv1 *rtv1)
{
	int		num_obj;

	num_obj = -1;
	while (++num_obj < SIZE_OBJ)
	{
		if (RT_OBJ.size < 0)
			error_exit("Bad size object: too small size object[0-1999999]");
		if (RT_OBJ.size >= 2000000)
			error_exit("Bad size object: too big size object[1-1999999]");
		RT_OBJ.size_pow = RT_OBJ.size * RT_OBJ.size;
	}
}
