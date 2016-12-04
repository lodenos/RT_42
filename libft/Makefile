# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#              #
#    Updated: 2016/11/27 16:21:01 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fclean, clean, re

FLAGS = -Wall -Wextra -Werror #-Weverything -Wno-padded

NAME = libft.a

SRC = 							\
		src/free_tab.c			\
		src/ft_atoi.c			\
		src/ft_bzero.c			\
		src/ft_itoa.c			\
		src/ft_isalnum.c		\
		src/ft_isalpha.c		\
		src/ft_isascii.c		\
		src/ft_isdigit.c		\
		src/ft_isprint.c		\
		src/ft_lstadd.c			\
		src/ft_lstdel.c			\
		src/ft_lstdelone.c		\
		src/ft_lstiter.c		\
		src/ft_lstmap.c			\
		src/ft_lstnew.c			\
		src/ft_memalloc.c		\
		src/ft_memccpy.c		\
		src/ft_memchr.c			\
		src/ft_memcpy.c			\
		src/ft_memcmp.c			\
		src/ft_memdel.c			\
		src/ft_memmove.c		\
		src/ft_memset.c			\
		src/ft_putchar.c		\
		src/ft_putchar_err.c	\
		src/ft_putchar_fd.c		\
		src/ft_putendl.c		\
		src/ft_putendl_fd.c		\
		src/ft_putnbr.c			\
		src/ft_putnbr_fd.c		\
		src/ft_putstr.c			\
		src/ft_putstr_err.c		\
		src/ft_putstr_fd.c		\
		src/ft_putstr_tab.c		\
		src/ft_strchr.c			\
		src/ft_strcat.c			\
		src/ft_strclr.c			\
		src/ft_strcmp.c			\
		src/ft_strcmp_case.c	\
		src/ft_strcpy.c			\
		src/ft_strdel.c			\
		src/ft_strdup.c			\
		src/ft_strequ.c			\
		src/ft_striter.c		\
		src/ft_striteri.c		\
		src/ft_strjoin.c		\
		src/ft_strlcat.c		\
		src/ft_strlen.c			\
		src/ft_strlen_tab.c		\
		src/ft_strmap.c			\
		src/ft_strmapi.c		\
		src/ft_strnbr_idtchar.c	\
		src/ft_strncat.c		\
		src/ft_strnequ.c		\
		src/ft_strnew.c			\
		src/ft_strnstr.c		\
		src/ft_strncmp.c		\
		src/ft_strncpy.c		\
		src/ft_strrchr.c		\
		src/ft_strsplit.c		\
		src/ft_strstr.c			\
		src/ft_strsub.c			\
		src/ft_strtrim.c		\
		src/ft_tolower.c		\
		src/ft_toupper.c		\
		src/get_next_line.c		\
		src/matrix_sqrt.c		\
		src/matrix_sqrt_free.c

OBJ = $(SRC:src/%.c=%.o)

HEAD = -I ./head

all: $(NAME)

$(NAME):
	@echo "----------------------------------------"
	@echo "Compiling libft  ..."
	@echo "Compiling in .o  ..."
	@gcc -c $(SRC) $(HEAD) $(FLAGS)
	@echo "Creating $(NAME) ..."
	@ar rc $(NAME) $(OBJ)
	@echo "Ranlib           ..."
	@ranlib $(NAME)
	@echo "Library Created  OK"
	@echo "----------------------------------------"

clean:
	@echo "----------------------------------------"
	@echo "Deleting all .o"
	@rm -rf $(OBJ)
	@echo "The folder is clean !"
	@echo "----------------------------------------"

fclean:
	@echo "----------------------------------------"
	@echo "Deleting Library.a and all .o"
	@rm -rf $(NAME) $(OBJ)
	@echo "The folder is clean"
	@echo "----------------------------------------"

re: fclean all
