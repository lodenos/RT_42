# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glodenos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/08 14:11:35 by glodenos          #+#    #+#              #
#    Updated: 2016/09/22 01:11:44 by glodenos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPENCL	=	-framework OpenCL

FLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g3 -O3 -lm -Weverything  \
			-Wno-padded

HEAD	=	-I ./head

LIBFT	=	-I ./libft/head -L ./libft -lft

NAME	=	RT

SDL     =   -framework Opengl -framework SDL2

SDL_UNIX	=   -lSDL2

SRC		=	\
			src/main.c				    \
			src/play_scene.c		    \
			src/event_everything.c	    \
			src/get_scene.c			    \
			src/create_window.c		    \
			src/progress_bar.c		    \
			src/camera.c			    \
			src/run_raytracing.c        \
            src/sphere.c                \
            src/light.c                 \
            src/coordinates_collision.c \
            src/diffused_light.c		\
			src/lunch_opencl.c			\
			src/err_cl.c				\
			src/get_src_opencl.c		\
			src/specular_light.c		\
			src/vector_formula_1.c		\
			src/vector_formula_2.c		\
			src/get_camera.c			\
			src/get_spot.c				\
			src/cone.c					\
			src/get_object.c			\
			src/ft_strconc.c			\
			src/parser.c				\
			src/ft_lstpushback.c		\
			src/plan.c					\
			src/cylinder.c				\
			src/torus.c

all:
	@make -C ./libft
	@gcc -o $(NAME) $(SRC) $(HEAD) $(LIBFT) $(SDL) $(OPENCL) $(FLAGS)

unix: 
	@make -C ./libft
	@gcc -o $(NAME) $(SRC) $(HEAD) $(LIBFT) $(SDL_UNIX) $(FLAGS)

clean:
	@make -C ./libft

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)

re: fclean all
