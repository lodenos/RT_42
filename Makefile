# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glodenos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/08 14:11:35 by glodenos          #+#    #+#              #
#    Updated: 2016/09/28 21:15:19 by glodenos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPENCL	=	-framework OpenCL

FLAGS	=	-Wall -Werror -Wextra -O3 -lm -Weverything -Wno-padded

SEG		=	-fsanitize=address -g3

HEAD	=	-I ./head

LIBFT	=	-I ./libft/head -L ./libft -lft

NAME	=	RT

SDL     =   -framework Opengl -framework SDL2

SDL_UNIX	=   -lSDL2

SRC		=										\
			src/object/sphere.c					\
			src/object/cone.c					\
			src/object/torus.c					\
			src/object/cylinder.c				\
			src/object/plan.c					\
												\
			src/opencl/err_cl.c					\
			src/opencl/get_src_opencl.c			\
			src/opencl/lunch_opencl.c			\
												\
			src/parser/get_camera.c				\
			src/parser/get_color.c				\
			src/parser/get_cone.c				\
			src/parser/get_cylinder.c			\
			src/parser/get_file_mlt.c			\
			src/parser/get_file_obj.c			\
			src/parser/get_file_ortv1.c			\
			src/parser/get_file_raw.c			\
			src/parser/get_plan.c				\
			src/parser/get_scene.c				\
			src/parser/get_sphere.c				\
			src/parser/get_spot.c				\
			src/parser/get_torus.c				\
			src/parser/get_vec3.c				\
												\
			src/ray_tracing/camera.c			\
			src/ray_tracing/check_object.c		\
			src/ray_tracing/play_scene.c		\
			src/ray_tracing/run_raytracing.c	\
												\
			src/SDL2/create_window.c			\
			src/SDL2/event_everything.c			\
			src/SDL2/pixel_put.c				\
												\
			src/shader/diffused_light.c			\
			src/shader/light.c					\
			src/shader/limit_rgba.c				\
			src/shader/specular_light.c			\
												\
			src/vector/coordinates_collision.c	\
			src/vector/vector_formula_1.c		\
			src/vector/vector_formula_2.c		\
												\
			src/main.c

all:
	@make -j -C ./libft
	@gcc -o $(NAME) $(SRC) $(HEAD) $(LIBFT) $(SDL) $(OPENCL)

unix: 
	@make -C ./libft
	@gcc -o $(NAME) $(SRC) $(HEAD) $(LIBFT) $(SDL_UNIX) $(FLAGS)

norm:
	@make -j -C ./libft
	@gcc -o $(NAME) $(SRC) $(HEAD) $(LIBFT) $(SDL) $(OPENCL) $(FLAGS)

debug:
	@make -j -C ./libft
	@gcc -o $(NAME) $(SRC) $(HEAD) $(LIBFT) $(SDL) $(OPENCL) $(SEG)

clean:
	@make -C ./libft

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)

re: fclean all
