# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 20:17:11 by ndahib            #+#    #+#              #
#    Updated: 2023/08/11 13:18:09 by nelallao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***************************************VARIABLES******************************#
CC = cc
CFLAGS =

NAME = cub3D

SRCS = main.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = MLX42
GLFW_DIR = $(shell brew --prefix glfw)
MLX_LIB = -L$(MLX_DIR) -lmlx42
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit
GLFW_LIB = -L$(GLFW_DIR)/lib -lglfw

LIBS = $(MLX_LIB) $(FRAMEWORKS) $(GLFW_LIB)

INCLUDE = -I$(MLX_DIR) -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(INCLUDE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
