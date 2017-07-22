/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json_parser_general.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:50:14 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/07/13 15:37:16 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	ft_json_parser_general4(t_options *o, t_options_json *oj)
{
	oj->draft_x = cJSON_GetObjectItemCaseSensitive(oj->opt, "draft_x");
	o->draft_x = oj->draft_x->valueint;
	oj->draft_y = cJSON_GetObjectItemCaseSensitive(oj->opt, "draft_y");
	if (!cJSON_IsNumber(oj->draft_y) || !cJSON_IsNumber(oj->draft_x))
		ft_pars_err("draft ssaa error");
	o->draft_y = oj->draft_y->valueint;
	oj->j_screen_size = cJSON_GetObjectItemCaseSensitive(oj->opt,
			"screen_size");
	oj->j_size_x = cJSON_GetObjectItemCaseSensitive(oj->j_screen_size, "width");
	oj->j_size_y = cJSON_GetObjectItemCaseSensitive(oj->j_screen_size,
		"height");
	if (!cJSON_IsNumber(oj->j_size_y) || !cJSON_IsNumber(oj->j_size_x))
		ft_pars_err("Screen size parameters error");
	o->size_y = oj->j_size_y->valueint;
	o->size_x = oj->j_size_x->valueint;
}

void	ft_json_parser_general5(t_options *o, t_options_json *oj)
{
	oj->j_bg_color = cJSON_GetObjectItemCaseSensitive(oj->opt,
			"background_color");
	oj->l_col_r = cJSON_GetObjectItemCaseSensitive(oj->j_bg_color, "r");
	oj->l_col_g = cJSON_GetObjectItemCaseSensitive(oj->j_bg_color, "g");
	oj->l_col_b = cJSON_GetObjectItemCaseSensitive(oj->j_bg_color, "b");
	if (!cJSON_IsNumber(oj->l_col_r) || !cJSON_IsNumber(oj->l_col_g)
			|| !cJSON_IsNumber(oj->l_col_b))
		ft_pars_err("Lights color parameters error");
	o->bg_color.red = oj->l_col_r->valuedouble;
	o->bg_color.green = oj->l_col_g->valuedouble;
	o->bg_color.blue = oj->l_col_b->valuedouble;
	if (o->bg_color.red > 255 || o->bg_color.red < 0 ||
			o->bg_color.green > 255 || o->bg_color.green < 0 ||
			o->bg_color.blue > 255 || o->bg_color.blue < 0)
		ft_pars_err("Background color parameters error, use from 0 to 255");
	oj->j_depth_rec = cJSON_GetObjectItemCaseSensitive(oj->opt, "depth_rec");
	if (!cJSON_IsNumber(oj->j_depth_rec))
		ft_pars_err("depth_rec error");
	o->depth_rec = oj->j_depth_rec->valueint;
	oj->j_speed = cJSON_GetObjectItemCaseSensitive(oj->opt, "speed");
	if (!cJSON_IsNumber(oj->j_speed))
		ft_pars_err("speed error");
	o->speed = oj->j_speed->valueint;
}

void	ft_json_parser_asvirido(t_options *o, t_options_json *oj)
{
	oj->recursion = cJSON_GetObjectItemCaseSensitive(oj->opt, "recursion");
	if (!cJSON_IsBool(oj->recursion))
		ft_pars_err("recursion parameter error");
	o->recursion = oj->recursion->valueint;
	oj->horizont = cJSON_GetObjectItemCaseSensitive(oj->opt, "horizont");
	if (!cJSON_IsBool(oj->horizont))
		ft_pars_err("horizont parameter error");
	o->horizont = oj->horizont->valueint;
	oj->outline = cJSON_GetObjectItemCaseSensitive(oj->opt, "outline");
	if (!cJSON_IsBool(oj->outline))
		ft_pars_err("outline parameter error");
	o->outline = oj->outline->valueint;
	oj->carton = cJSON_GetObjectItemCaseSensitive(oj->opt, "carton");
	if (!cJSON_IsBool(oj->carton))
		ft_pars_err("carton parameter error");
	o->carton = oj->carton->valueint;
}

void	ft_json_parser_outline_color(t_options *o, t_options_json *oj)
{
	oj->ol_color = cJSON_GetObjectItemCaseSensitive(oj->opt,
			"outline_color");
	oj->o_col_r = cJSON_GetObjectItemCaseSensitive(oj->ol_color, "r");
	oj->o_col_g = cJSON_GetObjectItemCaseSensitive(oj->ol_color, "g");
	oj->o_col_b = cJSON_GetObjectItemCaseSensitive(oj->ol_color, "b");
	if (!cJSON_IsNumber(oj->o_col_r) || !cJSON_IsNumber(oj->o_col_g)
			|| !cJSON_IsNumber(oj->o_col_b))
		ft_pars_err("Lights color parameters error");
	o->outline_color.red = oj->o_col_r->valuedouble;
	o->outline_color.green = oj->o_col_g->valuedouble;
	o->outline_color.blue = oj->o_col_b->valuedouble;
	if (o->outline_color.red > 255 || o->bg_color.red < 0 ||
			o->outline_color.green > 255 || o->outline_color.green < 0 ||
			o->outline_color.blue > 255 || o->outline_color.blue < 0)
		ft_pars_err("Background color parameters error, use from 0 to 255");
}

void	ft_json_parser_general(char *file, t_all_data *data)
{
	t_options		*o;
	t_options_json	*oj;

	o = (t_options*)ft_memalloc(sizeof(t_options) + 1);
	oj = (t_options_json*)ft_memalloc(sizeof(t_options_json) + 1);
	oj->root = cJSON_Parse(file);
	oj->opt = cJSON_GetObjectItemCaseSensitive(oj->root, "general");
	if (!cJSON_IsObject(oj->opt))
		ft_pars_err("General parameters error");
	oj->light_off_on = cJSON_GetObjectItemCaseSensitive(oj->opt,
			"light_off_on");
	ft_json_parser_general1(o, oj);
	ft_json_parser_general2(o, oj);
	ft_json_parser_general3(o, oj);
	ft_json_parser_general4(o, oj);
	ft_json_parser_general5(o, oj);
	ft_json_parser_asvirido(o, oj);
	ft_json_parser_outline_color(o, oj);
	data->all_opt = ft_copy(o, sizeof(t_options));
	data->all_opt->objects_count = data->all_obj->obj_count;
	cJSON_Delete(oj->root);
	free(o);
	free(oj);
}
