# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 22:14:35 by afrasch           #+#    #+#              #
#    Updated: 2021/10/27 11:42:30 by afrasch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INC = -Iinclude
LIB = -Llibs -lft -Llibs -lmlx
FLAGS = -framework OpenGL -framework AppKit -lm -o "fractol" \
-Wall -Wextra -Werror
CC = gcc
SRC = main.c \
fractol.c \
init.c \
put_image.c \
hooks.c \
handle_input.c \
mandelbrot.c \
julia.c \
pomegranate.c \
burningship.c \
set_colour.c \
move.c \
set_hooks.c \
switch.c \
helper.c

# COLOURS
YELLOW = \033[0;33m
RED = \033[1;31m
RESET = \033[0m

all:$(NAME)
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
$(NAME) : libraries
	@gcc $(FLAGS) -O3 $(SRC) $(INC) $(LIB)
	@echo "$(YELLOW)compiled!$(RESET)"
slow : fclean libraries
	@gcc $(FLAGS) $(SRC) $(INC) $(LIB)
	@echo "$(YELLOW)compiled!$(RESET)"
libraries:
	@make -silent -C ./minilibx
	@make -silent -C ./libs/libft
	@cp -f ./libs/libft/libft.a libs
	@rm -f ./libs/libft/libft.a
	@make clean -C ./libs/libft
	@echo "$(YELLOW)libraries ready!$(RESET)"
bonus: $(NAME)
clean:
	@rm -f *.o *~
	@echo "$(RED).o files removed$(RESET)"
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)cleaned up!$(RESET)"
re: fclean all
