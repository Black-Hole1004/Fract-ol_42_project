# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 14:24:42 by ahmaymou          #+#    #+#              #
#    Updated: 2023/02/27 18:17:07 by ahmaymou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FRACTOL

SRCS_OBJ = $(shell ls | grep .c | grep -v main | grep -v fract | grep -v screenshots)
SRC = main.c

FLAGS = -Wall -Werror -Wextra

CC = cc

LIBS = libft/libft.a printf/libftprintf.a

EXEC = fractol

INC_EXC = -I /usr/local/include
FRAMEWORK = -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit

OBJ = $(SRCS_OBJ:.c=.o)

all : $(NAME)

%.o: %.c fract_ol.h
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME) : libft_printf prog

libft_printf :
	@make -C libft
	@make -C printf

prog :  $(OBJ) fract_ol.h
	$(CC) $(INC_EXC) $(FLAGS) $(SRC) -Imlx $(FRAMEWORK) $(OBJ) $(LIBS) -o $(EXEC)
	@rm -rf $(LIBS)

clean :
	@make clean -C libft
	@make clean -C printf
	@rm -rf $(OBJ)
fclean : clean
	rm -rf $(LIBS) $(EXEC)

re : fclean all

.PHONY : all clean fclean re