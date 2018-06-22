#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 14:09:53 by ykaplien          #+#    #+#              #
#    Updated: 2018/05/29 14:09:55 by ykaplien         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
SRCS = srcs/main.c srcs/validation.c srcs/window.c
FLAGS = -Wall -Werror -Wextra
HEADER = includes/fdf.h
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@ make -C libft re
	@ gcc $(FLAGS) -I $(HEADER) -lmlx -framework OpenGL -framework AppKit $(SRCS) libft/libft.a -o $(NAME)

%.o:%.c
	@ gcc -o $@ -c $< -I ./libft/

clean:
	@ make -C libft clean

fclean: clean
	@ rm -f $(NAME)
	@ make -C libft fclean

re: fclean all