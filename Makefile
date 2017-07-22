# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makafile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asvirido <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 14:27:54 by asvirido          #+#    #+#              #
#    Updated: 2017/07/13 19:38:34 by asvirido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

FLAGS = -c #-Wall -Wextra -Werror

FLAGS2 = -c #-Wall -Wextra

MLX = -lmlx -framework OpenGL -framework AppKit SRC/create_rt/CJSON/cJSON.c

HEADER = head.h

MLX_SRC =		./SRC/mlx_src/create_img.c										\
				./SRC/mlx_src/object_mlx.c										\
				./SRC/mlx_src/valid_size_win.c									\
				./SRC/mlx_src/create_xpm.c										\
				./SRC/mlx_src/put_img.c											\
				./SRC/mlx_src/create_color.c									\
				./SRC/mlx_src/protected_color.c									\
				./SRC/mlx_src/midle_color.c										\
				./SRC/mlx_src/set_color.c										\
				./SRC/mlx_src/color_filters/black_and_white.c					\
				./SRC/mlx_src/color_filters/sepia.c								\
				./SRC/mlx_src/color_filters/darkroom.c							\


VECTOR =		./SRC/Vector/add_vector.c										\
				./SRC/Vector/cos_vector.c										\
				./SRC/Vector/module_vector.c									\
				./SRC/Vector/mult_vector.c										\
				./SRC/Vector/product_vectors.c									\
				./SRC/Vector/scalar_vector.c									\
				./SRC/Vector/sub_vector.c										\
				./SRC/Vector/create_vector.c									\
				./SRC/Vector/dot_vector.c										\
				./SRC/Vector/normal_vector.c									\
				./SRC/Vector/set_vector.c										\
				./SRC/Vector/division_vector.c									\
				./SRC/Vector/constuct_vector.c									\
				./SRC/Vector/vector_rotation.c									\

EVENT = 		./SRC/event/destroy.c											\
				./SRC/event/event_key.c											\
				./SRC/event/event_camera.c										\
				./SRC/event/event_mouse.c										\
				./SRC/event/control_camera/move_back_camera.c					\
				./SRC/event/control_camera/move_forward_camera.c				\
				./SRC/event/control_camera/move_right_camera.c					\
				./SRC/event/control_camera/move_left_camera.c					\
				./SRC/event/control_camera/move_down_camera.c					\
				./SRC/event/control_camera/move_up_camera.c						\
				./SRC/event/control_camera/rotation_x.c							\
				./SRC/event/control_camera/rotation_y.c							\
				./SRC/event/control_camera/rotation_z.c							\

CREATE_RT =		./SRC/create_rt/create_ray.c									\
				./SRC/create_rt/create_rt.c										\
				./SRC/create_rt/create_map.c									\
				./SRC/create_rt/ssaa.c											\
				./SRC/create_rt/init_obj.c										\
				./SRC/create_rt/init_obj_2.c										\
	 			./SRC/create_rt/ft_json_parser_obj.c							\
	   			./SRC/create_rt/ft_json_parser_general.c						\
	   			./SRC/create_rt/ft_pars_light.c									\
	   			./SRC/create_rt/valid.c 										\
	   			./SRC/create_rt/pars.c 											\
	   			./SRC/create_rt/pars_2.c 											\


RT =			./SRC/ray_tracing/ray_tracing.c									\
				./SRC/ray_tracing/intersect.c									\
				./SRC/ray_tracing/intersect_2.c									\
				./SRC/ray_tracing/intersect_obj/intersect_sphere.c				\
				./SRC/ray_tracing/intersect_obj/intersect_cd_disc.c				\
				./SRC/ray_tracing/intersect_obj/intersect_cone.c				\
				./SRC/ray_tracing/intersect_obj/intersect_cylinder.c			\
				./SRC/ray_tracing/intersect_obj/intersect_half_sphere.c			\
				./SRC/ray_tracing/intersect_obj/discriminant.c					\
				./SRC/ray_tracing/intersect_obj/intersect_disc.c				\
				./SRC/ray_tracing/intersect_obj/intersect_ellipsoid.c			\
				./SRC/ray_tracing/intersect_obj/intersect_plane_limit.c			\
				./SRC/ray_tracing/ft_light.c									\
				./SRC/ray_tracing/get_color.c									\
				./SRC/ray_tracing/motion_blur.c									\
				./SRC/ray_tracing/check_intersect_object.c						\
				./SRC/ray_tracing/find_point_intersect.c						\
				./SRC/ray_tracing/get_intersect_normal.c						\
				./SRC/ray_tracing/find_normal_cylinder.c						\
				./SRC/ray_tracing/find_normal_cone.c							\
				./SRC/ray_tracing/light_intersect.c								\
				./SRC/ray_tracing/all_shadow.c									\
				./SRC/ray_tracing/all_light.c									\
				./SRC/ray_tracing/thread.c										\
				./SRC/ray_tracing/filters.c										\

FT =			./SRC/function/main.c											\
				./SRC/function/mlx_use.c										\
				./SRC/function/error_exit.c										\
				./SRC/function/ft_bzero.c										\
				./SRC/function/ft_memset.c										\
				./SRC/function/ft_strchr.c										\
				./SRC/function/ft_strdup.c										\
				./SRC/function/ft_strjoin.c										\
				./SRC/function/ft_strlen.c										\
				./SRC/function/ft_memalloc.c									\
				./SRC/function/ft_strnew.c										\
				./SRC/function/get_next_line.c									\
				./SRC/function/becap.c 											\

SRC =			$(FT)															\
				$(VECTOR)														\
				$(CREATE_RT)													\
				$(MLX_SRC)														\
				$(RT)															\
				$(EVENT)														\

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	@ gcc -o $(NAME) $(BINS) $(MLX)
	@ make clean

SRC/Vector/%.o: SRC/Vector/%.c
	@ gcc $(FLAGS2) -o  $@ $<
SRC/mlx_src/%.o: SRC/mlx_src/%.c
	@ gcc $(FLAGS2) -o  $@ $<
SRC/event/%.o: SRC/event/%.c
	@ gcc $(FLAGS2) -o  $@ $<
SRC/ft_math/%.o: SRC/ft_math/%.c
	@ gcc $(FLAGS2) -o  $@ $<
SRC/function/%.o: SRC/function/%.c
	@ gcc $(FLAGS2) -o  $@ $<
SRC/ray_tracing/intersect_obj/%.o: SRC/ray_tracing/intersect_obj/%.c
	@ gcc $(FLAGS2) -o  $@ $<
SRC/ray_tracing/Lighting_Model/%.o: SRC/ray_tracing/Lighting_Model/%.c
	@ gcc $(FLAGS2) -o  $@ $<
SRC/ray_tracing/%.o: SRC/ray_tracing/%.c
	@ gcc $(FLAGS) -o  $@ $<
SRC/create_rt/%.o: SRC/create_rt/%.c
	@ gcc $(FLAGS2) -o  $@ $<

clean:
	@ /bin/rm -f $(BINS)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all
