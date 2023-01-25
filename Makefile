# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 14:24:42 by ahmaymou          #+#    #+#              #
#    Updated: 2023/01/23 14:41:50 by ahmaymou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FRACTOL

SRCS_OBJ = $(shell ls | grep .c | grep -v main | grep -v fract)
SRC = main.c
SRC_B = main_bonus.c

FLAGS = -Wall -Werror -Wextra

CC = cc

LIBS = libft.a libftprintf.a libmlx.a

EXEC = fractol
EXEC_B = bonus

INC_EXC = -I /usr/local/include
FRAMEWORK = -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit

OBJ = $(SRCS_OBJ:.c=.o)

all : $(NAME)

%.o: %.c fract_ol.h
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME) : libft_printf prog

libft_printf :
	@cd libft && make bonus && mv libft.a ..
	@cd printf && make re && mv libftprintf.a .. && cd ..
	@cd mlx && make && mv libmlx.a .. && cd ..

prog :  $(OBJ) fract_ol.h
	$(CC) $(INC_EXC) $(FLAGS) $(SRC) -Imlx $(FRAMEWORK) $(OBJ) $(LIBS) -g -o $(EXEC)
	@rm -rf $(LIBS)
bonus : $(NAME) bonus_prog

bonus_prog : fract_ol.h
	$(CC) $(FLAGS) $(SRC_B) $(OBJ) $(LIBS) -o $(EXEC_B)
	@rm -rf $(LIBS)

clean :
	@cd libft && make clean
	@cd printf && make clean
	@rm -rf $(OBJ)
fclean : clean
	rm -rf $(LIBS) $(EXEC) $(EXEC_B)

re : fclean all
re_bonus: fclean bonus

.PHONY : all clean fclean re re_bonus