/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:04:01 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/07/13 15:10:34 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	ft_pars_pos_rot(t_json_obj *j, t_all_data *data, int i)
{
	j->j_position = cJSON_GetObjectItemCaseSensitive(j->j_object, "position");
	j->pos_x1 = cJSON_GetObjectItemCaseSensitive(j->j_position, "x");
	j->pos_y1 = cJSON_GetObjectItemCaseSensitive(j->j_position, "y");
	j->pos_z1 = cJSON_GetObjectItemCaseSensitive(j->j_position, "z");
	if (!cJSON_IsNumber(j->pos_x1) || !cJSON_IsNumber(j->pos_y1) ||
			!cJSON_IsNumber(j->pos_y1))
		ft_pars_err("Position parameters error");
	data->all_obj[i].position.x = j->pos_x1->valuedouble;
	data->all_obj[i].position.y = j->pos_y1->valuedouble;
	data->all_obj[i].position.z = j->pos_z1->valuedouble;
	j->j_obj_rot = cJSON_GetObjectItemCaseSensitive(j->j_object, "rotation");
	j->rot_x1 = cJSON_GetObjectItemCaseSensitive(j->j_obj_rot, "x");
	j->rot_y1 = cJSON_GetObjectItemCaseSensitive(j->j_obj_rot, "y");
	j->rot_z1 = cJSON_GetObjectItemCaseSensitive(j->j_obj_rot, "z");
	if (!cJSON_IsNumber(j->rot_x1) || !cJSON_IsNumber(j->rot_y1)
			|| !cJSON_IsNumber(j->rot_y1))
		ft_pars_err("Rotation parameters error");
	data->all_obj[i].rotation.x = j->rot_x1->valuedouble;
	data->all_obj[i].rotation.y = j->rot_y1->valuedouble;
	data->all_obj[i].rotation.z = j->rot_z1->valuedouble;
}

void	ft_pars_color(t_json_obj *j, t_all_data *data, int i)
{
	j->j_color = cJSON_GetObjectItemCaseSensitive(j->j_object, "color");
	j->j_red = cJSON_GetObjectItemCaseSensitive(j->j_color, "r");
	j->j_green = cJSON_GetObjectItemCaseSensitive(j->j_color, "g");
	j->j_blue = cJSON_GetObjectItemCaseSensitive(j->j_color, "b");
	if (!cJSON_IsNumber(j->j_red) || !cJSON_IsNumber(j->j_green)
			|| !cJSON_IsNumber(j->j_blue))
		ft_pars_err("Color parameters error");
	data->all_obj[i].color.red = j->j_red->valueint;
	data->all_obj[i].color.green = j->j_green->valueint;
	data->all_obj[i].color.blue = j->j_blue->valueint;
	if (data->all_obj[i].color.red > 255 || data->all_obj[i].color.red < 0 ||
			data->all_obj[i].color.green > 255 ||
			data->all_obj[i].color.green < 0 ||
			data->all_obj[i].color.blue > 255 ||
			data->all_obj[i].color.blue < 0)
		ft_pars_err("Color parameters error, use from 0 to 255");
}

void	ft_pars_smthg(t_json_obj *j, t_all_data *data, int i)
{
	j->j_reflection = cJSON_GetObjectItemCaseSensitive(j->j_object,
		"reflection");
	if (!cJSON_IsBool(j->j_reflection))
		ft_pars_err("reflection parameters error");
	data->all_obj[i].reflection = j->j_reflection->valueint;
	j->j_refraction = cJSON_GetObjectItemCaseSensitive(j->j_object,
		"refraction");
	if (!cJSON_IsBool(j->j_refraction))
		ft_pars_err("refraction parameters error");
	data->all_obj[i].refraction = j->j_refraction->valueint;
	j->j_param_refract = cJSON_GetObjectItemCaseSensitive(j->j_object,
		"param_refract");
	if (!cJSON_IsNumber(j->j_param_refract))
		ft_pars_err("Param_refract parameters error");
	data->all_obj[i].param_refract = j->j_param_refract->valuedouble;
	j->j_shines = cJSON_GetObjectItemCaseSensitive(j->j_object, "shines");
	if (!cJSON_IsNumber(j->j_shines))
		ft_pars_err("shines parameters error");
	data->all_obj[i].shines = j->j_shines->valuedouble;
}

void	ft_parse_all_obj(t_json_obj *j, t_object *o, t_all_data *data)
{
	int i;

	i = 0;
	data->all_obj = (t_object*)malloc(sizeof(t_object) * o->obj_count);
	while (i < o->obj_count)
	{
		ft_parse_opt(j, data, i);
		ft_pars_pos_rot(j, data, i);
		ft_pars_color(j, data, i);
		ft_pars_smthg(j, data, i);
		j->j_direction = cJSON_GetObjectItemCaseSensitive(j->j_object,
				"direction");
		j->dir_x1 = cJSON_GetObjectItemCaseSensitive(j->j_direction, "x");
		j->dir_y1 = cJSON_GetObjectItemCaseSensitive(j->j_direction, "y");
		j->dir_z1 = cJSON_GetObjectItemCaseSensitive(j->j_direction, "z");
		if (!cJSON_IsNumber(j->dir_x1) || !cJSON_IsNumber(j->dir_y1)
				|| !cJSON_IsNumber(j->dir_z1))
			ft_pars_err("Direction parameters error");
		data->all_obj[i].direction.x = j->dir_x1->valuedouble;
		data->all_obj[i].direction.y = j->dir_y1->valuedouble;
		data->all_obj[i].direction.z = j->dir_z1->valuedouble;
		i++;
	}
}

void	ft_json_parser_obj(char *file, t_all_data *data)
{
	t_json_obj	*j;
	t_object	*o;

	o = (t_object*)ft_memalloc(sizeof(t_object));
	j = (t_json_obj*)ft_memalloc(sizeof(t_json_obj));
	j->j_root = cJSON_Parse(file);
	j->j_format = cJSON_GetObjectItemCaseSensitive(j->j_root, "objects");
	if (!cJSON_IsArray(j->j_format))
		ft_pars_err("map error (objects array)");
	o->obj_count = cJSON_GetArraySize(j->j_format);
	ft_parse_all_obj(j, o, data);
	data->all_obj->obj_count = o->obj_count;
	cJSON_Delete(j->j_root);
	free(j);
	free(o);
}
