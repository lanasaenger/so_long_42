# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lavinia <lavinia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 20:06:17 by lamachad          #+#    #+#              #
#    Updated: 2025/02/16 04:47:34 by lavinia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := so_long
CC        := cc
CFLAGS    := -g3 -Wextra -Wall -Werror
LIBMLX    := ./libraries/MLX42
LIBFT    := ./libraries/libft
FLAGSMLX := -ldl -lglfw -pthread -lm
HEADERS		:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a
SRCS	:= ./src/main.c \
						./src/move.c \
						./src/render.c \
						./src/load.c \
						./src/validate.c \
						./src/flood_fill.c \
			

OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@echo "Cleaning previous MLX42 build..."
	@rm -rf $(LIBMLX)/build
	@echo "Building MLX42..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@echo "Building libft..."
	@make -C $(LIBFT) $(FLAGS) --no-print-directory

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT)/libft.a
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJS) $(LIBS) -o $(NAME) $(FLAGSMLX)

clean:
	@echo "Cleaning up object files..."
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@find $(LIBFT) -name "*.o" -delete

fclean: clean
	@echo "Cleaning up binary and libraries..."
	@rm -rf $(NAME)
	@find $(LIBFT) -name "*.a" -delete

re: fclean all

.PHONY: all clean fclean re libmlx libft