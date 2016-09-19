# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glodenos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/08 14:11:35 by glodenos          #+#    #+#              #
#    Updated: 2016/09/19 03:47:28 by glodenos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPENCL	=	-framework OpenCL

FLAGS	=	-fsanitize=address -g3 -O3 -lm #-Weverything -Wall -Werror -Wextra -lm -O3	\
			-g3   #

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
            src/diffused_light.c

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
