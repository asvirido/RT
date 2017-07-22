/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkachyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:34:20 by otkachyk          #+#    #+#             */
/*   Updated: 2017/07/21 15:34:21 by otkachyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	ft_pars_err(char *str)
{
	printf("\033[1;31m_______%s_______\n\033[0m", str);
	exit(1);
}

void	ft_json_parser_general1(t_options *o, t_options_json *oj)
{
	if (!cJSON_IsBool(oj->light_off_on))
		ft_pars_err("light parameter error");
	o->light_off_on = oj->light_off_on->valueint;
	oj->lambert_light = cJSON_GetObjectItemCaseSensitive(oj->opt,
			"lambert_light");
	if (!cJSON_IsBool(oj->lambert_light))
		ft_pars_err("lambert light parameter error");
	o->lambert_light = oj->lambert_light->valueint;
	oj->cel_shaded = cJSON_GetObjectItemCaseSensitive(oj->opt, "cel_shaded");
	if (!cJSON_IsBool(oj->cel_shaded))
		ft_pars_err("cel_shaded parameter error");
	o->cel_shaded = oj->cel_shaded->valueint;
	oj->blinn_fong = cJSON_GetObjectItemCaseSensitive(oj->opt, "blinn_fong");
	if (!cJSON_IsBool(oj->blinn_fong))
		ft_pars_err("blinn_fong  error");
	o->blinn_fong = oj->blinn_fong->valueint;
	oj->shadow = cJSON_GetObjectItemCaseSensitive(oj->opt, "shadow");
	if (!cJSON_IsBool(oj->shadow))
		ft_pars_err("shadow parameter error");
	o->shadow = oj->shadow->valueint;
}

void	ft_json_parser_general2(t_options *o, t_options_json *oj)
{
	oj->view_normal = cJSON_GetObjectItemCaseSensitive(oj->opt, "view_normal");
	if (!cJSON_IsBool(oj->view_normal))
		ft_pars_err("view_normal parameter error");
	o->view_normal = oj->view_normal->valueint;
	oj->view_point = cJSON_GetObjectItemCaseSensitive(oj->opt, "view_point");
	if (!cJSON_IsBool(oj->view_point))
		ft_pars_err("view_point parameter error");
	o->view_point = oj->view_point->valueint;
	oj->ssaa = cJSON_GetObjectItemCaseSensitive(oj->opt, "ssaa");
	if (!cJSON_IsBool(oj->ssaa))
		ft_pars_err("ssaa parameter error");
	o->ssaa = oj->ssaa->valueint;
	oj->size_ssaa = cJSON_GetObjectItemCaseSensitive(oj->opt, "size_ssaa");
	if (!cJSON_IsNumber(oj->size_ssaa))
		ft_pars_err("size_ssaa ssaa error");
	o->size_ssaa = oj->size_ssaa->valueint;
	oj->fxaa = cJSON_GetObjectItemCaseSensitive(oj->opt, "fxaa");
	if (!cJSON_IsBool(oj->fxaa))
		ft_pars_err("fxaa parameter error");
	o->fxaa = oj->fxaa->valueint;
	oj->filters = cJSON_GetObjectItemCaseSensitive(oj->opt, "filters");
	if (!cJSON_IsBool(oj->filters))
		ft_pars_err("filters parameter error");
}

void	ft_json_parser_general3(t_options *o, t_options_json *oj)
{
	o->filters = oj->filters->valueint;
	oj->darkroom = cJSON_GetObjectItemCaseSensitive(oj->opt, "darkroom");
	if (!cJSON_IsBool(oj->darkroom))
		ft_pars_err("darkroom parameter error");
	o->darkroom = oj->darkroom->valueint;
	oj->black_and_white = cJSON_GetObjectItemCaseSensitive(oj->opt,
			"black_and_white");
	if (!cJSON_IsBool(oj->black_and_white))
		ft_pars_err("black_and_white parameter error");
	o->black_and_white = oj->black_and_white->valueint;
	oj->sepia = cJSON_GetObjectItemCaseSensitive(oj->opt, "sepia");
	if (!cJSON_IsBool(oj->sepia))
		ft_pars_err("sepia parameter error");
	o->sepia = oj->sepia->valueint;
	oj->motion_blur = cJSON_GetObjectItemCaseSensitive(oj->opt, "motion_blur");
	if (!cJSON_IsBool(oj->motion_blur))
		ft_pars_err("motion_blur parameter error");
	o->motion_blur = oj->motion_blur->valueint;
	oj->size_blur = cJSON_GetObjectItemCaseSensitive(oj->opt, "size_blur");
	if (!cJSON_IsNumber(oj->size_blur))
		ft_pars_err("size_blur ssaa error");
	o->size_blur = oj->size_blur->valueint;
	oj->fov_on = cJSON_GetObjectItemCaseSensitive(oj->opt, "fov_on");
}
