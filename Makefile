# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 15:54:54 by jmoussu           #+#    #+#              #
#    Updated: 2019/02/07 18:40:43 by jmoussu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	srcs/main.c \
		srcs/ligne.c \
		srcs/utils.c \
		srcs/read.c \
		srcs/valid_file.c \
		srcs/parsing.c \
		srcs/display_list.c \
		srcs/make_link.c \
		srcs/freelist.c \
		srcs/mlx_main.c \
		srcs/maths.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

GREEN_OK = "\033[0;32mDONE !\033[00m"

all:  $(NAME)

$(NAME): $(OBJ)
	@cd libft && make
	@cd minilibx_macos && make
	@gcc -o $(NAME) $(CFLAGS) -I minilibx_macos $(OBJ) libft/libft.a -L minilibx_macos -lmlx -framework OpenGL -framework Appkit
	@echo fdf ${GREEN_OK}

%.o : %.c
	@clang -c $(CFLAGS) $< -o $@

onlyfdf:
	@gcc -o $(NAME) $(CFLAGS) -I minilibx_macos $(SRC) libft/libft.a -L minilibx_macos -lmlx -framework OpenGL -framework Appkit
	@echo onlyfdf ${GREEN_OK}

onlyfdfdebug:
	@gcc -o $(NAME) $(CFLAGS) -g -I minilibx_macos $(SRC) libft/libft.a -L minilibx_macos -lmlx -framework OpenGL -framework Appkit
	@echo onlyfdf debug ${GREEN_OK}

onlylibft:
	@cd libft && make

onlyminilibx:
	@cd minilibx_macos && make

clean:
	@rm -f $(OBJ)
	@cd libft && make clean
	@cd minilibx_macos && make clean
	@echo clean fdf ${GREEN_OK}

fclean: clean
	@rm -f $(NAME)
	@rm -rf fdf.dSYM
	@cd libft && make fclean
	@cd minilibx_macos && make fclean
	@echo fclean fdf ${GREEN_OK}

mclean: all clean

cleanexe:
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
