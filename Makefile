# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrandria <nrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:23:48 by nrandria          #+#    #+#              #
#    Updated: 2016/10/30 13:24:53 by glodenos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fclean, clean, re

SRC_PATH = src/

SRC_NAME = 	main.c									\
													\
			clustering/host.c						\
													\
			event_RT/event_RT.c						\
			event_RT/fps_info.c						\
													\
			move/matrix_rotate.c					\
													\
			object/sphere.c							\
			object/cone.c							\
			object/torus.c							\
			object/cylinder.c						\
			object/plan.c							\
													\
			opencl/err_cl.c							\
			opencl/err_cl_sub.c						\
			opencl/get_src_opencl.c					\
			opencl/lunch_opencl.c					\
													\
			parser/get_file_raw.c					\
													\
			parser/extension_obj/get_file_mlt.c		\
			parser/extension_obj/get_file_obj.c		\
													\
			parser/extension_ort/get_file_ort.c		\
			parser/extension_ort/get_ort_cone.c		\
			parser/extension_ort/get_ort_config.c	\
			parser/extension_ort/get_ort_cylinder.c	\
			parser/extension_ort/get_ort_group.c	\
			parser/extension_ort/get_ort_plan.c		\
			parser/extension_ort/get_ort_scene.c	\
			parser/extension_ort/get_ort_sphere.c	\
			parser/extension_ort/get_ort_texture.c	\
			parser/extension_ort/get_ort_torus.c	\
			parser/extension_ort/get_ort.c			\
													\
			parser/extension_ortv1/get_camera.c		\
			parser/extension_ortv1/get_color.c		\
			parser/extension_ortv1/get_cone.c		\
			parser/extension_ortv1/get_cylinder.c	\
			parser/extension_ortv1/get_file_ortv1.c	\
			parser/extension_ortv1/get_plan.c		\
			parser/extension_ortv1/get_scene.c		\
			parser/extension_ortv1/get_sphere.c		\
			parser/extension_ortv1/get_spot.c		\
			parser/extension_ortv1/get_torus.c		\
			parser/extension_ortv1/get_vec3.c		\
													\
			ray_tracing/camera.c					\
			ray_tracing/check_object.c				\
			ray_tracing/OCL_run_raytracing.c		\
			ray_tracing/play_scene.c				\
			ray_tracing/run_object.c				\
			ray_tracing/run_raytracing.c			\
													\
			SDL2/create_window.c					\
			SDL2/event_everything.c					\
			SDL2/init_keyboard.c					\
			SDL2/init_mouse.c						\
			SDL2/key_press.c						\
			SDL2/key_release.c						\
			SDL2/push_to_window.c					\
			SDL2/window_resize.c					\
													\
			shader/bump_mapping.c					\
			shader/diffused_light.c					\
			shader/filtered_RGB.c					\
			shader/filtered_r_b.c 					\
			shader/light.c							\
			shader/limit.c							\
			shader/specular_light.c					\
			shader/super_sampling.c 				\
													\
			vector/coordinates_collision.c			\
			vector/vector_formula_1.c				\
			vector/vector_formula_2.c

OBJ_PATH	=	obj/

INCLUDE 	= 	-Ihead -Ilibft/head

LDFLAGS		=	-Llibft
LDLIBS 		= 	-lft

NAME 		=	RT

CC 			=	clang

CFLAGS 		=	#-Wall -Wextra -Werror -Ofast -Weverything -Wno-padded
LIBGRPH 	= 	-lm -framework OpenGL -framework SDL2 -framework OpenCL -lpthread

OBJ_NAME 	=	$(addsuffix .o, $(basename $(SRC_NAME)))

SRC 		=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ 		=	$(addprefix $(OBJ_PATH),$(notdir $(OBJ_NAME)))

VPATH		=	$(shell find $(SRC_PATH) -type d)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@echo "\033[33mProject compilation\033[0m"
	@$(CC) $(LDFLAGS) $(LDLIBS) $(LIBGRPH) $^ -o $@
	@echo "\033[32mCompilation SUCCESS\033[0m"

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

debug:
	@gcc -g3 -fsanitize=address $(SRC) $(LIBGRPH) $(INCLUDE) $(LDLIBS) $(LDFLAGS)

clean:
	@echo "\033[33m.o's cleaning\033[0m"
	@rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
