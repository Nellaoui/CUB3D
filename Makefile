# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 20:17:11 by ndahib            #+#    #+#              #
#    Updated: 2023/08/15 10:51:48 by nelallao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***************************************VARIABLES******************************#
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = cub3D
SRCS = main.c checks.c mlx_hook.c
OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix obj/, $(OBJS))
OBJ_DIR = obj/

MLX_DIR = includes/MLX42
GLFW_DIR = $(shell brew --prefix glfw)
MLX_LIB = -L$(MLX_DIR) -lmlx42
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit
GLFW_LIB = -L$(GLFW_DIR)/lib -lglfw
LIBFT = includes/libft/libft.a

LIBS = $(MLX_LIB) $(FRAMEWORKS) $(GLFW_LIB) $(LIBFT)

INCLUDE = -I$(MLX_DIR) -Iinclude -Iincludes/libft

all: $(OBJ_DIR) $(NAME) $(LIBFT)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDE) $(LIBS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C includes/libft

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make clean -C includes/libft
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C includes/libft
	rm -f $(NAME)

re: fclean all
	make re -C includes/libft
