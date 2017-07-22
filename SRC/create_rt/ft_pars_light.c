/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 15:11:21 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/07/13 15:13:51 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	ft_lght_pos(t_options_json *lj, t_all_data *data, int i)
{
	lj->j_arr_lght = cJSON_GetArrayItem(lj->j_lights, i);
	lj->lght_pos = cJSON_GetObjectItemCaseSensitive(lj->j_arr_lght, "position");
	lj->lght_x = cJSON_GetObjectItemCaseSensitive(lj->lght_pos, "x");
	lj->lght_y = cJSON_GetObjectItemCaseSensitive(lj->lght_pos, "y");
	lj->lght_z = cJSON_GetObjectItemCaseSensitive(lj->lght_pos, "z");
	if (!cJSON_IsNumber(lj->lght_x) || !cJSON_IsNumber(lj->lght_y) ||
			!cJSON_IsNumber(lj->lght_x))
		ft_pars_err("Lights position parameters error");
	data->light_pos[i].position.x = lj->lght_x->valuedouble;
	data->light_pos[i].position.y = lj->lght_y->valuedouble;
	data->light_pos[i].position.z = lj->lght_z->valuedouble;
	data->light_pos[i].id = i;
}

void	ft_lght_dir(t_options_json *lj, t_all_data *data, int i)
{
	lj->lght_dir = cJSON_GetObjectItemCaseSensitive(lj->j_arr_lght,
			"direction");
	lj->l_dir_x = cJSON_GetObjectItemCaseSensitive(lj->lght_dir, "x");
	lj->l_dir_y = cJSON_GetObjectItemCaseSensitive(lj->lght_dir, "y");
	lj->l_dir_z = cJSON_GetObjectItemCaseSensitive(lj->lght_dir, "z");
	if (!cJSON_IsNumber(lj->l_dir_x) || !cJSON_IsNumber(lj->l_dir_y) ||
			!cJSON_IsNumber(lj->l_dir_z))
		ft_pars_err("Lights direction parameters error");
	data->light_pos[i].direction.x = lj->l_dir_x->valuedouble;
	data->light_pos[i].direction.y = lj->l_dir_y->valuedouble;
	data->light_pos[i].direction.z = lj->l_dir_z->valuedouble;
}

void	ft_lght_color(t_options_json *lj, t_all_data *data, int i)
{
	lj->lght_col = cJSON_GetObjectItemCaseSensitive(lj->j_arr_lght, "color");
	lj->l_col_r = cJSON_GetObjectItemCaseSensitive(lj->lght_col, "r");
	lj->l_col_g = cJSON_GetObjectItemCaseSensitive(lj->lght_col, "g");
	lj->l_col_b = cJSON_GetObjectItemCaseSensitive(lj->lght_col, "b");
	if (!cJSON_IsNumber(lj->l_col_r) || !cJSON_IsNumber(lj->l_col_g) ||
			!cJSON_IsNumber(lj->l_col_b))
		ft_pars_err("Lights color parameters error");
	data->light_pos[i].color.red = lj->l_col_r->valuedouble;
	data->light_pos[i].color.green = lj->l_col_g->valuedouble;
	data->light_pos[i].color.blue = lj->l_col_b->valuedouble;
	if (data->light_pos[i].color.red > 255 ||
			data->light_pos[i].color.red < 0 ||
			data->light_pos[i].color.green > 255 ||
			data->light_pos[i].color.green < 0 ||
			data->light_pos[i].color.blue > 255 ||
			data->light_pos[i].color.blue < 0)
		ft_pars_err("Lights color parameters error, use from 0 to 255");
}

void	ft_pars_lights(char *file, t_all_data *data)
{
	int				i;
	int				lght_count;
	t_options_json	*lj;

	i = 0;
	lj = (t_options_json*)ft_memalloc(sizeof(t_options_json));
	lj->root = cJSON_Parse(file);
	lj->j_lights = cJSON_GetObjectItemCaseSensitive(lj->root, "lights");
	if (!cJSON_IsArray(lj->j_lights))
		ft_pars_err("map error (lights must be array)");
	lght_count = cJSON_GetArraySize(lj->j_lights);
	data->light_pos = (t_light*)malloc(sizeof(t_light) * (lght_count + 1));
	data->all_opt->lght_count = lght_count;
	while (i < lght_count)
	{
		ft_lght_pos(lj, data, i);
		ft_lght_dir(lj, data, i);
		ft_lght_color(lj, data, i);
		i++;
	}
	cJSON_Delete(lj->root);
	free(lj);
}
