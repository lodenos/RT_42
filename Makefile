# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrandria <nrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:23:48 by nrandria          #+#    #+#              #
#    Updated: 2016/12/12 15:09:12 by glodenos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fclean, clean, re, linux, windows, debug

SRC_PATH = src/

SRC_NAME = 	main.c										\
														\
			clustering/cluster_create_buffer.c			\
			clustering/cluster_parallelisation.c		\
			clustering/cluster_read_buffer.c			\
			clustering/cluster_write_buffer.c			\
			clustering/host/host.c						\
			clustering/host/slave_connection.c			\
			clustering/slave/slave.c					\
														\
			event_rt/event_rt.c							\
			event_rt/fps_info.c							\
			event_rt/move.c								\
			event_rt/rotate.c							\
														\
			move/matrix_rotate.c						\
														\
			object/sphere.c								\
			object/cone.c								\
			object/torus.c								\
			object/cylinder.c							\
			object/plan.c								\
														\
			opencl/err_cl.c								\
			opencl/err_cl_sub.c							\
			opencl/get_src_opencl.c						\
			opencl/lunch_opencl.c						\
														\
			parser/get_file_raw.c						\
			parser/get_scene.c							\
														\
			parser/extension_obj/get_file_mlt.c			\
			parser/extension_obj/get_file_obj.c			\
														\
			parser/extension_ort/get_file_ort.c			\
			parser/extension_ort/get_info_angle.c		\
			parser/extension_ort/get_info_color.c		\
			parser/extension_ort/get_info_diffuse.c		\
			parser/extension_ort/get_info_position.c	\
			parser/extension_ort/get_info_radius.c		\
			parser/extension_ort/get_info_rotate.c		\
			parser/extension_ort/get_ort_camera.c		\
			parser/extension_ort/get_ort_config.c		\
			parser/extension_ort/get_ort_group.c		\
			parser/extension_ort/get_ort_obj_info.c		\
			parser/extension_ort/get_ort_scene.c		\
			parser/extension_ort/get_ort_spotlight.c	\
			parser/extension_ort/get_ort_texture.c		\
			parser/extension_ort/get_ort.c				\
														\
			ray_tracing/camera.c						\
			ray_tracing/check_object.c					\
			ray_tracing/OCL_run_raytracing.c			\
			ray_tracing/play_scene.c					\
			ray_tracing/run_object.c					\
			ray_tracing/run_raytracing.c				\
														\
			SDL2/create_window.c						\
			SDL2/event_everything.c						\
			SDL2/init_keyboard.c						\
			SDL2/init_mouse.c							\
			SDL2/key_press.c							\
			SDL2/key_release.c							\
			SDL2/push_to_window.c						\
			SDL2/window_resize.c						\
														\
			shader/effect/limit.c							\
			shader/effect/maths_perlin.c					\
			shader/effect/perlin.c							\
			shader/effect/voronoi.c							\
															\
			shader/post-processing/filtered_black_white.c	\
			shader/post-processing/filtered_rgb.c			\
			shader/post-processing/sepia.c					\
			shader/post-processing/super_sampling.c			\
															\
			shader/pre-processing/bump_mapping.c			\
			shader/pre-processing/diffused_light.c			\
			shader/pre-processing/light.c					\
			shader/pre-processing/specular_light.c			\
															\
			shader/maths_perlin.c							\
			shader/perlin.c									\
			shader/voronoi.c								\
															\
			vector/coordinates_collision.c					\
			vector/vector_formula_1.c						\
			vector/vector_formula_2.c

OBJ_PATH	=	obj/

INCLUDE 	= 	-I head -I libft/head

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

#-------------------------------------------------------------------------------

FLAGS		= 	#-Wall -Wextra -Werror

LIBFT 		=	-L libft -lft

OPENCL_WIN	=	-I "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v8.0\include"	\
				-L "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v8.0\lib\x64"	\
				-l OpenCL

SDL2_WIN	=	-I "C:\Development\SDL2-2.0.5\x86_64-w64-mingw32\include"	\
				-L "C:\Development\SDL2-2.0.5\x86_64-w64-mingw32\lib"		\
				-lmingw32 -lSDL2main -lSDL2

#-------------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@echo "\033[33mProject compilation\033[0m"
	@$(CC) $(LDFLAGS) $(LDLIBS) $(LIBGRPH) $^ -o $@
	@echo "\033[32mCompilation SUCCESS\033[0m"

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

linux:

window:
	@echo "----------------------------------------"
	@gcc $(FLAGS) $(SRC) $(INCLUDE) $(LIBFT) $(OPENCL_WIN) $(SDL2_WIN) -std=gnu11 -lm -lws2_32
	@echo "----------------------------------------"

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
