# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaymou <ahmaymou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 18:47:21 by ahmaymou          #+#    #+#              #
#    Updated: 2023/01/09 14:54:36 by ahmaymou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalpha.c ft_memcmp.c ft_strdup.c ft_strnstr.c \
        ft_atoi.c ft_isascii.c ft_memcpy.c ft_strlcat.c    ft_strrchr.c \
        ft_bzero.c ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_tolower.c \
        ft_calloc.c  ft_isprint.c ft_memset.c ft_strlen.c ft_toupper.c \
        ft_isalnum.c ft_memchr.c ft_strchr.c ft_strncmp.c ft_strjoin.c ft_substr.c \
		ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECT = $(SRC:.c=.o)

BONUS_OBJECT = $(BONUS_SRC:.c=.o)

CC = cc

# echo1 = @echo "\033[92mCompiled all the files successfully !!! :) \033[0m"
# echo2 = @echo "\033[92mCompiled bonus files successfully !!! :) \033[0m"
# echo3 = @echo "\033[36mArchive created successfully !!! :) \033[m"
# echo4 = @echo "\033[31mbonus added to the archive successfully !!! :) \033[m"

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.c libft.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJECT) libft.h
	@ar rc $(NAME) $(OBJECT)

bonus : $(NAME) $(BONUS_OBJECT)
	@ar rc $(NAME) $(OBJECT) $(BONUS_OBJECT)

clean :
	@rm -f $(OBJECT) $(BONUS_OBJECT)

fclean : clean
	@rm -f $(NAME)

re : fclean all

re_b:fclean bonus
	

#a : all bonus
	
#.PHONY : clean fclean all re bonus