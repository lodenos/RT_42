# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glodenos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/14 16:09:43 by glodenos          #+#    #+#              #
#    Updated: 2016/09/13 14:04:50 by anespoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	=	-Wall -Werror -Wextra -lm -g3 -O3

HEAD	=	-I./head

LIBFT	=	-I./libft/head -L./libft -lft

MLX		= 	-L./minilibx_macos -I./minilibx_macos -lmlx -framework OpenGL	\
			-framework AppKit

NAME	=	RTv1

SRC		=	\
			get_scene.c				\
			main.c					\
			get_camera.c			\
			get_object.c			\
			get_spot.c				\
			sphere.c				\
			play_scene.c			\
			coordinates_collision.c	\
			diffused_light.c		\
			light.c					\
			event_keyboard.c		\
			run_raytracing.c		\
			plan.c					\
			cone.c					\
			torus.c					\
			cylinder.c				\
			ft_vec.c

$(NAME): $(OBJ)

all: $(NAME)

$(NAME):
	@make -C ./libft
	@make -C ./minilibx_macos
	@gcc -o $(NAME) $(SRC) $(HEAD) $(MLX) $(LIBFT) $(FLAGS)

clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft
	@make clean -C ./minilibx_macos

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
	@make fclean -C ./libft
	@make clean -C ./minilibx_macos

make re: fclean all
