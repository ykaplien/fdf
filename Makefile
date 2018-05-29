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

NAME := fdf
LIB_DIR := ./libft/
SRC_DIR := ./srcs/
OBJ_DIR := ./objects/
INC_DIR := ./inc/
SRCS := main.c
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
CC := gcc
FLAGS := -Wall -Wextra -Werror
FRAMEWORKS := -framework OpenGL -framework AppKit
MLX_LIB := -L /usr/local/lib/ -lmlx
LIBFT = $(LIB_DIR)libft›.a
LIBFT_FLAGS := -L $(LIB_DIR) -lft
LIBFT_INC := $(LIB_DIR)includes
HDR_FLAGS := -I $(LIBFT_INC) -I $(INC_DIR) -I /usr/locale/include
all: $(NAME)
$(NAME): $(LIBFT) $(OBJ)
    $(CC) $(OBJ) $(FLAGS) $(HDR_FLAGS) -o $(NAME) $(LIBFT) $(FRAMEWORKS) $(MLX_LIB)
$(OBJ): | $(OBJ_DIR)
$(OBJ_DIR):
    mkdir $(OBJ_DIR)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
    $(CC) -c $< -o $@ $(FLAGS) $(HDR_FLAGS)
$(LIBFT):
    make -C $(LIB_DIR)
clean:
    make clean -C $(LIB_DIR)
    rm -f $(OBJ)
fclean:
    make fclean -C $(LIB_DIR)
    rm -f $(NAME)
    rm -rf $(OBJ_DIR)
re: fclean all