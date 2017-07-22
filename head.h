/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:00:34 by asvirido          #+#    #+#             */
/*   Updated: 2017/05/17 22:49:38 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include <fcntl.h>
# include <string.h>
# include "SRC/mlx_src/mlx_src.h"
# include "SRC/create_rt/create_rt.h"
# include <stdio.h>
# include <string.h>
# include <pthread.h>

# define RAY_ORIGIN 			rtv1->ray->origin
# define RAY_DIRECTION 			rtv1->ray->direction
# define L_RAY_ORIGIN 			rtv1->light_ray->origin
# define L_RAY_DIRECTION 		rtv1->light_ray->direction
# define CONE_COS_22			cone.two_cone_cos_two
# define CONE_COS_2				cone.cone_cos_two
# define CONE_SIN_22			cone.two_cone_sin_two
# define CONE_SIN_2				cone.cone_sin_two
# define RT_OBJ					rtv1->data->all_obj[num_obj]
# define GRT_OBJ					rtv1->data->all_obj[g_num_obj]
# define RT						rtv1
# define SIZE_OBJ 				rtv1->data->all_opt->objects_count
# define SIZE_LIGHT 			rtv1->data->all_opt->lght_count
# define MLX_MY					rtv1->obj->mlx
# define WIN_MY					rtv1->obj->win
# define L						rtv1->data->light_pos[i]
# define SCREEN					rtv1->screen[i].ray
# define BACKGROUND				rtv1->data->all_opt->bg_color
# define OPTION					rtv1->data->all_opt
# define DIR_NORMAL 			RT->screen[i].dir_ssaa[j]
# define X 						RT->screen2[i].ray->x
# define Y 						RT->screen2[i].ray->y
# define GREEN					"\033[32;1m"
# define RESET					"\033[0m"
# define TRUE					1
# define FALSE					0
# define SPHERE				1
# define PLANE					2
# define DISC					3
# define CYLINDER				4
# define CONE					5
# define HALF_SPHERE			6
# define ELLIPSOID			7
# define CD_DISC				8
# define MINIMUM				1.5

typedef struct	s_val_math
{
	t_vector	dist;
	double		a;
	double		b;
	double		c;
	double		d;
	double		t0;
	double		t1;
}				t_val_math;

typedef struct	s_val_intersect
{
	int			i;
	int			num_obj;
	int			hit;
}				t_val_intersect;

typedef struct	s_val_vector
{
	t_vector		point;
	t_vector		n_point;
	t_vector		tmp;
	t_color			color;
	t_color			*rgb;
	t_vector		ray;
}				t_val_vector;

typedef struct	s_rtv1
{
	t_mlx			*obj;
	t_all_data		*data;
	t_img			*img;
	t_ray			*ray;
	t_ray			*light_ray;
	t_screen		*screen;
	t_screen		*screen2;
	t_val_vector	*val;
	int				*hit;
	int				procent_one;
	int				loading_progress;
	int				count;
	t_vector		*pos;
}				t_rtv1;

t_rtv1			*create_rtv1(t_env *e, char *s);
t_vector		calc_ssaa(t_rtv1 *rtv1, t_vector *dir, int j);
void			init_demo(t_rtv1 *rtv1);
void			draw_rt(t_rtv1 *rtv1);
void			effect_filtres(t_rtv1 *rtv1);
void			ft_ssaa(t_rtv1 *rtv1, int i, t_color *res);
void			carton(t_rtv1 *rtv1);
void			outline(t_rtv1 *rtv1);
void			*thread_draw1(void *parameter);
void			ray_tracing(t_rtv1 *rtv1);
void			fov(t_rtv1 *rtv1, int x, int y);
void			motion_blur(t_rtv1 *rtv1);
t_color		intersect(t_rtv1 *rtv1, int i);
int			check_intersect_object(t_rtv1 *rt, double *t, int i, t_ray *r);
int			intersect_sphere(t_ray *r, t_object obj, double *t);
int			intersect_cylinder(t_ray *r, t_object c, double *t);
int			intersect_cone(t_ray *r, t_object c, double *t);
int			intersect_disc(t_ray *r, t_object obj, double *t);
int			intersect_ellipsoid(t_ray *ray, t_object ellips, double *t);
int			intersect_half_sphere(t_ray *r, t_object *obj, double *t);
int			intersect_plane_limit(t_ray *ray, t_object plane, double *t);
int			intersect_cd_disc(t_ray *ray, t_object object, double *t);
int			discriminant(double *t, t_val_math val);
int			light_intersect(t_rtv1 *rt, double *t);
t_color		ft_light(t_rtv1 *rt, double *t_min, int num_obj);
void			all_shadow(t_rtv1 *r, int num_obj, t_val_vector *val, int *hit);
void			all_light(t_rtv1 *r, t_val_vector *val, int *hit, int num_obj);
t_vector		point_intersect(t_ray *ray, double *t);
t_vector		get_intersect_normal(t_rtv1 *rt, int num_obj, t_vector *point);
t_vector		find_normal_cylinder(t_object cylinder, t_vector *point);
t_vector		find_normal_cone(t_object cone, t_vector *point);
t_color		get_color(t_rtv1 *rtv1, int num_obj);
int			destroy(void);
int			event_key(int keycode, t_rtv1 *rtv1);
int			event_mouse(int keycode, int x, int y, t_rtv1 *rtv1);
int			event_camera(int keycode, t_rtv1 *rt);
void			move_left_camera(t_rtv1 *rtv1);
void			move_right_camera(t_rtv1 *rtv1);
void			move_forward_camera(t_rtv1 *rtv1);
void			move_back_camera(t_rtv1 *rtv1);
void			move_up_camera(t_rtv1 *rtv1);
void			move_down_camera(t_rtv1 *rtv1);
void			zoom(int keycode, int x, int y, t_rtv1 *rtv1);
void			rotation_x(t_rtv1 *rtv1, int keycode);
void			rotation_y(t_rtv1 *rtv1, int keycode);
void			rotation_z(t_rtv1 *rtv1, int keycode);
void			valid_option(t_rtv1 *rtv1);
void			mlx_use(t_rtv1 *rtv1);
int			error_exit(char *error);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *str, int c, size_t len);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
void			*ft_copy(void *data, size_t size);
void			becap(t_rtv1 *rtv1);
int			get_next_line(int fd, char **line);
void			rot_z(t_vector *v, int angle);
void			rot_y(t_vector *v, int angle);
void			rot_x(t_vector *v, int angle);
void			parsing_color(t_rtv1 *rtv1);
void			parsing_direction(t_rtv1 *rtv1);
void			parcing_size_pow(t_rtv1 *rtv1);
void			parcing_shines(t_rtv1 *rtv1);
void			parcing_half_sphere(t_rtv1 *rtv1);
void			parcing_cone(t_rtv1 *rtv1);
t_color		slow_intersect(t_rtv1 *rtv1, int i);
t_color		fast_intersect(t_rtv1 *rtv1, int i);
void			anti_vector(t_vector *v);
void			view_point_or_normal(t_rtv1 *rtv1, t_val_vector *val);
void			parcing_reftact(t_rtv1 *rtv1);

#endif
