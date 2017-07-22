/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:51:49 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/29 19:51:51 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_RT_H
# define CREATE_RT_H

# include "../Vector/vector.h"
# include "../mlx_src/mlx_src.h"
# include <stdio.h>
# include <math.h>
# include "CJSON/cJSON.h"
# define SPHERE 1
# define PLANE 2
# define CONE 5
# define CYLINDER 4
# define DISC 3
# define HALF_SPHERE 6

typedef struct	s_object
{
	char			*type;
	int				obj_count;
	int				id;
	double			size;
	t_color			color;
	t_vector		direction;
	t_vector		position;
	t_vector		rotation;
	int				reflection;
	int				refraction;
	double			param_refract;
	int				shines;
	double			light_n;
	double			radius_disc;
	double			size_pow;
	double			cone_cos_two;
	double			cone_sin_two;
	double			two_cone_cos_two;
	double			two_cone_sin_two;
}				t_object;

typedef struct	s_json_obj
{
	cJSON		*j_root;
	cJSON		*j_format;
	cJSON		*j_object;
	cJSON		*j_color;
	cJSON		*j_type;
	cJSON		*j_position;
	cJSON		*pos_x1;
	cJSON		*pos_y1;
	cJSON		*pos_z1;
	cJSON		*j_obj_rot;
	cJSON		*j_direction;
	cJSON		*dir_x1;
	cJSON		*dir_y1;
	cJSON		*dir_z1;
	cJSON		*rot_x1;
	cJSON		*rot_y1;
	cJSON		*rot_z1;
	cJSON		*j_red;
	cJSON		*j_green;
	cJSON		*j_blue;
	cJSON		*j_size;
	cJSON		*j_reflection;
	cJSON		*j_refraction;
	cJSON		*j_param_refract;
	cJSON		*j_shines;
}				t_json_obj;

typedef struct	s_options_json
{
	cJSON		*root;
	cJSON		*opt;
	cJSON		*light_off_on;
	cJSON		*lambert_light;
	cJSON		*cel_shaded;
	cJSON		*blinn_fong;
	cJSON		*shadow;
	cJSON		*view_normal;
	cJSON		*view_point;
	cJSON		*fieldofview;
	cJSON		*fov_on;
	cJSON		*fov;
	cJSON		*motion_blur;
	cJSON		*size_blur;
	cJSON		*size_x;
	cJSON		*size_y;
	cJSON		*size_screen;
	cJSON		*name_win;
	cJSON		*size_ssaa;
	cJSON		*ssaa;
	cJSON		*fxaa;
	cJSON		*filters;
	cJSON		*darkroom;
	cJSON		*black_and_white;
	cJSON		*sepia;
	cJSON		*draft_x;
	cJSON		*draft_y;
	cJSON		*camera_position;
	cJSON		*cam_x;
	cJSON		*cam_y;
	cJSON		*cam_z;
	cJSON		*j_lights;
	cJSON		*j_arr_lght;
	cJSON		*lght_pos;
	cJSON		*lght_x;
	cJSON		*lght_y;
	cJSON		*lght_z;
	cJSON		*lght_dir;
	cJSON		*l_dir_x;
	cJSON		*l_dir_y;
	cJSON		*l_dir_z;
	cJSON		*lght_col;
	cJSON		*l_col_r;
	cJSON		*l_col_g;
	cJSON		*l_col_b;
	cJSON		*o_col_r;
	cJSON		*o_col_g;
	cJSON		*o_col_b;
	cJSON		*j_depth_rec;
	cJSON		*j_speed;
	cJSON		*j_bg_color;
	cJSON		*ol_color;
	cJSON		*j_screen_size;
	cJSON		*j_size_y;
	cJSON		*j_size_x;
	cJSON		*recursion;
	cJSON		*horizont;
	cJSON		*outline;
	cJSON		*carton;

}				t_options_json;

typedef struct	s_options
{
	t_color		bg_color;
	t_color		outline_color;
	int			light_off_on;
	int			lambert_light;
	int			cel_shaded;
	int			blinn_fong;
	int			shadow;
	int			view_normal;
	int			view_point;
	int			fov_on;
	int			fov;
	int			motion_blur;
	int			size_blur;
	int			size_screen;
	char		*name_win;
	int			size_ssaa;
	int			ssaa;
	int			fxaa;
	int			fieldofview;
	int			filters;
	int			darkroom;
	int			black_and_white;
	int			sepia;
	int			draft_x;
	int			draft_y;
	t_vector	cam_pos;
	int			depth_rec;
	int			lght_count;
	int			objects_count;
	int			speed;
	int			size_x;
	int			size_y;
	int			recursion;
	int			horizont;
	int			outline;
	int			carton;
}				t_options;

typedef	struct	s_ray
{
	t_vector	*origin;
	t_vector	*direction;
}				t_ray;

typedef struct	s_screen
{
	t_vector	*ray;
	t_vector	*dir_ssaa;
	t_color		*color;
	int			id;
	int			w;
}				t_screen;

typedef struct	s_light
{
	int			id;
	t_vector	position;
	t_vector	direction;
	t_color		color;
	double		ambient;
}				t_light;

typedef struct	s_all_data
{
	t_object	*all_obj;
	t_light		*light_pos;
	t_options	*all_opt;
}				t_all_data;

typedef struct	s_env
{
	int			fd;
}				t_env;

t_ray			*create_ray(void);
t_screen		*create_map(int size_x, int size_y);
t_light			*create_all_light(int size);

void			ft_init(t_env *e, char *file);
t_all_data		*ft_parsing(t_env *e);
char			*ft_read_file(t_env *e);
void			ft_json_parser_obj(char *str, t_all_data *data);
void			ft_json_parser_general(char *file, t_all_data *data);
void			ft_pars_err(char *str);
void			ft_pars_lights(char *file, t_all_data *data);
void			ft_json_parser_general5(t_options *o, t_options_json *oj);
void			ft_json_parser_general4(t_options *o, t_options_json *oj);
void			ft_json_parser_general3(t_options *o, t_options_json *oj);
void			ft_json_parser_general2(t_options *o, t_options_json *oj);
void			ft_json_parser_general1(t_options *o, t_options_json *oj);
void			ft_check_objtype(char *str, t_all_data *data, int i);
void			ft_parse_opt(t_json_obj *j, t_all_data *data, int i);
void			ft_pars_pos_rot(t_json_obj *j, t_all_data *data, int i);
void			ft_pars_color(t_json_obj *j, t_all_data *data, int i);
void			ft_parse_all_obj(t_json_obj *j, t_object *o, t_all_data *data);

#endif
